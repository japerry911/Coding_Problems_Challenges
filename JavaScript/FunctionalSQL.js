var query = function () {
  return {
    result: [],
    data: [],
    selectColumns: [],
    statementsMade: [],
    whereConditions: [],
    groupBys: [],
    havingGroup: [],
    orderByComp: null,
    whereOr: false,
    execute: function () {
      let tempResult = this.data;

      if (this.whereOr) {
        tempResult = tempResult.filter((table) => {
          for (const condition of this.whereConditions) {
            if (condition(table)) {
              return true;
            }
          }
          return false;
        });
      } else {
        tempResult = tempResult.filter((table) => {
          for (const condition of this.whereConditions) {
            if (!condition(table)) {
              return false;
            }
          }
          return true;
        });
      }

      if (this.groupBys.length > 0) {
        this.result = Object.entries(
          multGroupBys(tempResult, this.groupBys)
        ).map((element) =>
          isNaN(element[0])
            ? [...element]
            : [Number(element[0]), ...element.slice(1)]
        );
      } else {
        this.result = tempResult;
      }

      if (this.havingGroup.length > 0) {
        for (const havingGroupFunction of this.havingGroup) {
          this.result = this.result.filter(havingGroupFunction);
        }
      }

      if (this.selectColumns.length > 0) {
        this.result = this.result.map(this.selectColumns[0]);
      }

      if (this.orderByComp) {
        this.result = this.result.sort(this.orderByComp);
      }

      return this.result;
    },
    duplicateStatementChecker: function () {
      // Check for SELECT duplicates
      if (
        this.statementsMade.filter((statement) => statement === "SELECT")
          .length > 1
      ) {
        throw Error("Duplicate SELECT");
      }

      // Check for FROM duplicates
      if (
        this.statementsMade.filter((statement) => statement === "FROM").length >
        1
      ) {
        throw Error("Duplicate FROM");
      }

      // Check for GROUP BY duplicates
      if (
        this.statementsMade.filter((statement) => statement === "GROUP BY")
          .length > 1
      ) {
        throw Error("Duplicate GROUPBY");
      }

      // Check for ORDER BY duplicates
      if (
        this.statementsMade.filter((statement) => statement === "ORDER BY")
          .length > 1
      ) {
        throw Error("Duplicate ORDERBY");
      }
      return this;
    },
    select: function (...selectStatement) {
      this.statementsMade.push("SELECT");
      this.duplicateStatementChecker();

      if (selectStatement) {
        this.selectColumns = selectStatement;
      }
      return this;
    },
    from: function (...tableArray) {
      this.statementsMade.push("FROM");
      this.duplicateStatementChecker();

      if (tableArray.length === 1) {
        this.data = [...tableArray[0]];
      } else {
        const dataArray = [];
        for (const tableRow1 of [...tableArray[0]]) {
          for (const tableRow2 of [...tableArray[1]]) {
            dataArray.push([tableRow1, tableRow2]);
          }
        }
        this.data = dataArray;
      }

      return this;
    },
    where: function (...conditions) {
      if (conditions.length > 1) {
        this.whereOr = true;
      }

      if (conditions.length > 0) {
        for (const condition of conditions) {
          this.whereConditions.push(condition);
        }
      }
      return this;
    },
    groupBy: function (...groups) {
      this.statementsMade.push("GROUP BY");
      this.duplicateStatementChecker();

      for (let group of groups) {
        this.groupBys.push(group);
      }
      return this;
    },
    having: function (group) {
      if (group) {
        this.havingGroup.push(group);
      }
      return this;
    },
    orderBy: function (comparison) {
      this.statementsMade.push("ORDER BY");
      this.duplicateStatementChecker();

      if (comparison) {
        this.orderByComp = comparison;
      }

      return this;
    },
  };
};

function multGroupBys(data, attribs) {
  attribs = Array.from(attribs);
  if (attribs.length === 1) {
    return groupBy(data, attribs[0]);
  }
  const property = attribs.shift();
  var grouped = groupBy(data, property);
  for (let key in grouped) {
    grouped[key] = Object.entries(
      multGroupBys(grouped[key], Array.from(attribs))
    );

    for (const sub of grouped[key]) {
      sub[0] = isNaN(sub[0]) ? sub[0] : Number(sub[0]);
    }
  }
  return grouped;
}

function groupBy(data, attrib) {
  return data.reduce((acc, row) => {
    let key = attrib(row);

    if (!acc[key]) {
      acc[key] = [];
    }
    acc[key].push(row);
    return acc;
  }, {});
}

// Test 1

var persons = [
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Michael", profession: "teacher", age: 50, maritalStatus: "single" },
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "married" },
  { name: "Rose", profession: "scientific", age: 50, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "single" },
  { name: "Anna", profession: "politician", age: 50, maritalStatus: "married" },
];

const test = [
  [
    "teacher",
    [
      {
        name: "Peter",
        profession: "teacher",
        age: 20,
        maritalStatus: "married",
      },
      {
        name: "Michael",
        profession: "teacher",
        age: 50,
        maritalStatus: "single",
      },
      {
        name: "Peter",
        profession: "teacher",
        age: 20,
        maritalStatus: "married",
      },
    ],
  ],
];

//console.log(test[0][1]);

function profession(person) {
  return person.profession;
}

function isTeacher(person) {
  return person.profession === "teacher";
}

function isPeter(person) {
  return person.name === "Peter";
}

function name(person) {
  return person.name;
}

function professionGroup(group) {
  return group[0];
}

function age(person) {
  return person.age;
}

function maritalStatus(person) {
  return person.maritalStatus;
}

function teacherJoin(join) {
  return join[0].teacherId === join[1].tutor;
}

function student(join) {
  return { studentName: join[1].studentName, teacherName: join[0].teacherName };
}

var teachers = [
  {
    teacherId: "1",
    teacherName: "Peter",
  },
  {
    teacherId: "2",
    teacherName: "Anna",
  },
];

var students = [
  {
    studentName: "Michael",
    tutor: "1",
  },
  {
    studentName: "Rose",
    tutor: "2",
  },
];

[
  [{ teacher: 1 }, { student: 2 }],
  [{ teacher: 1 }, { student: 2 }],
];

function tutor1(join) {
  return join[1].tutor === "1";
}

/*console.log(
  query().select(student).from(teachers, students).where(teacherJoin).execute()
);*/

var persons = [
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Michael", profession: "teacher", age: 50, maritalStatus: "single" },
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "married" },
  { name: "Rose", profession: "scientific", age: 50, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "single" },
  { name: "Anna", profession: "politician", age: 50, maritalStatus: "married" },
];

console.log(
  query()
    .select()
    .from(persons)
    .where(isTeacher)
    .groupBy(profession, name, age, maritalStatus)
    .execute()[0][1][0][1][0][1][0][1]
);

/*console.log(
  query()
    .select(student)
    .from(teachers, students)
    .where(teacherJoin)
    .where(tutor1)
    .execute()
);*/

function tutor01(join) {
  return join[1].tutor === "1";
}

/*console.log(
  query()
    .select(student)
    .from(teachers, students)
    .where(teacherJoin)
    .where(tutor01)
    .execute()
);*/

/*console.log(
  query()
    .select()
    .from(persons)
    .where(isTeacher)
    .groupBy(profession, name, age, maritalStatus)
    .execute()
);*/

// Test 2

function isEven(number) {
  return number % 2 === 0;
}

function parity(number) {
  return isEven(number) ? "even" : "odd";
}

function isPrime(number) {
  if (number < 2) {
    return false;
  }
  var divisor = 2;
  for (; number % divisor !== 0; divisor++);
  return divisor === number;
}

function prime(number) {
  return isPrime(number) ? "prime" : "divisible";
}

function odd(group) {
  return group[0] === "odd";
}

function descendentCompare(number1, number2) {
  return number2 - number1;
}

var numbers3 = [1, 2, 3, 4, 5, 7];

function lessThan3(number) {
  return number < 3;
}

function greaterThan4(number) {
  return number > 4;
}

/*console.log(
  query().select().from(numbers3).where(lessThan3, greaterThan4).execute()
);*/

var numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9];
var numbers1 = [1, 2];
var numbers2 = [4, 5];

/*console.log(
  query().select().from(numbers).orderBy(descendentCompare).execute()
);
console.log("------");*/
console.log(
  query().select().from(numbers).where(lessThan3, greaterThan4).execute()
);

/*console.log(
  query().select().from(numbers).orderBy(descendentCompare).execute() //[9,8,7,6,5,4,3,2,1]
);*/

//console.log(query().select().from(numbers1, numbers2).execute());

const test2 = [
  [
    "teacher",
    [
      [
        "Peter",
        [
          [
            20,
            [
              [
                "married",
                [
                  {
                    name: "Peter",
                    profession: "teacher",
                    age: 20,
                    maritalStatus: "married",
                  },
                  {
                    name: "Peter",
                    profession: "teacher",
                    age: 20,
                    maritalStatus: "married",
                  },
                ],
              ],
            ],
          ],
        ],
      ],
      [
        "Michael",
        [
          [
            50,
            [
              [
                "single",
                [
                  {
                    name: "Michael",
                    profession: "teacher",
                    age: 50,
                    maritalStatus: "single",
                  },
                ],
              ],
            ],
          ],
        ],
      ],
    ],
  ],
  [
    "scientific",
    [
      [
        "Anna",
        [
          [
            20,
            [
              [
                "married",
                [
                  {
                    name: "Anna",
                    profession: "scientific",
                    age: 20,
                    maritalStatus: "married",
                  },
                ],
              ],
              [
                "single",
                [
                  {
                    name: "Anna",
                    profession: "scientific",
                    age: 20,
                    maritalStatus: "single",
                  },
                ],
              ],
            ],
          ],
        ],
      ],
      [
        "Rose",
        [
          [
            50,
            [
              [
                "married",
                [
                  {
                    name: "Rose",
                    profession: "scientific",
                    age: 50,
                    maritalStatus: "married",
                  },
                ],
              ],
            ],
          ],
        ],
      ],
    ],
  ],
  [
    "politician",
    [
      [
        "Anna",
        [
          [
            50,
            [
              [
                "married",
                [
                  {
                    name: "Anna",
                    profession: "politician",
                    age: 50,
                    maritalStatus: "married",
                  },
                ],
              ],
            ],
          ],
        ],
      ],
    ],
  ],
];

// Sandbox
var persons2 = [
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Michael", profession: "teacher", age: 50, maritalStatus: "single" },
  { name: "Peter", profession: "teacher", age: 20, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "married" },
  { name: "Rose", profession: "scientific", age: 50, maritalStatus: "married" },
  { name: "Anna", profession: "scientific", age: 20, maritalStatus: "single" },
  { name: "Anna", profession: "politician", age: 50, maritalStatus: "married" },
];

function maritalStatus2(person) {
  return person.maritalStatus;
}

// GroupBy(s): Martial Status => Data
/*const output = persons2.reduce((acc, row) => {
  const key = maritalStatus2(row);
  if (acc.length === 0 || acc.findIndex((group) => group[0] === key) === -1) {
    const subArray = [key, []];
    subArray[1].push(row);
    acc.push(subArray);
  } else {
    acc[acc.findIndex((group) => group[0] === key)][1].push(row);
  }

  return acc;
}, []);
console.log(output);*/
//const output = Object.entries(_.groupBy(persons2, (row) => row.maritalStatus));
//console.log(output);

// GroupBy(s): Name -> Age -> Marital Status => Data
/*const groupBys = [profession, name, age, maritalStatus];
let output1 = Object.entries(nestGroupsBy(persons2, groupBys)).map((element) =>
  isNaN(element[0]) ? [...element] : [Number(element[0]), ...element.slice(1)]
);*/

//console.log(output1);

/*function multGroupBys(data, attribs) {
  attribs = Array.from(attribs);
  if (attribs.length === 1) {
    return groupBy(data, attribs[0]);
  }
  const property = attribs.shift();
  var grouped = groupBy(data, property);
  for (let key in grouped) {
    grouped[key] = Object.entries(
      nestGroupsBy(grouped[key], Array.from(attribs))
    );

    for (const sub of grouped[key]) {
      sub[0] = isNaN(sub[0]) ? sub[0] : Number(sub[0]);
    }
  }
  return grouped;
}

function groupBy(data, attrib) {
  return data.reduce((acc, row) => {
    let key = attrib(row);

    if (!acc[key]) {
      acc[key] = [];
    }
    acc[key].push(row);
    return acc;
  }, {});
}*/

/*for (let i = 0; i < groupBys.length; ++i) {
  if (i === 0) {
    output1 = _.groupBy(persons2, groupBys[i]);
  } else {
    _.forEach(output1, (value, key) => {
      output1[key] = Object.entries(_.groupBy(output1[key], groupBys[i]));
    });
    break;
  }
}*/
//console.log(output1);
/*let output1 = _.groupBy(persons2, age);
_.forEach(output1, (value, key) => {
  output1[key] = _.groupBy(output1[key], maritalStatus);
});*/

var numbers = [1, 2, 1, 3, 5, 6, 1, 2, 5, 6];

function greatThan1(group) {
  return group[1].length > 1;
}

function isPair(group) {
  return group[0] % 2 === 0;
}

function id(value) {
  return value;
}

function frequency(group) {
  return { value: group[0], frequency: group[1].length };
}

/*console.log(
  query()
    .select(frequency)
    .from(numbers)
    .groupBy(id)
    .having(greatThan1)
    .having(isPair)
    .execute()
);*/
// [{"value":2,"frequency":2},{"value":6,"frequency":2}])
