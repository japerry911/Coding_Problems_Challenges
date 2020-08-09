function SQLEngine(database) {
  this.execute = function (query) {
    const queryParsed = query.toLowerCase().split(" ");
    let returnArray = [];

    const selectedColumns = queryParsed.slice(1, queryParsed.indexOf("from"));
    const fromTable = queryParsed.slice(
      queryParsed.indexOf("from") + 1,
      queryParsed.indexOf("from") + 2
    );

    for (let selectedColumn of selectedColumns) {
      if (selectedColumn.indexOf(fromTable) > -1) {
        console.log(database[fromTable]);
      }
    }

    return returnArray;
  };
}

var movieDatabase = {
  movie: [
    { id: 1, name: "Avatar", directorID: 1 },
    { id: 2, name: "Titanic", directorID: 1 },
    { id: 3, name: "Infamous", directorID: 2 },
    { id: 4, name: "Skyfall", directorID: 3 },
    { id: 5, name: "Aliens", directorID: 1 },
  ],
  actor: [
    { id: 1, name: "Leonardo DiCaprio" },
    { id: 2, name: "Sigourney Weaver" },
    { id: 3, name: "Daniel Craig" },
  ],
  director: [
    { id: 1, name: "James Cameron" },
    { id: 2, name: "Douglas McGrath" },
    { id: 3, name: "Sam Mendes" },
  ],
  actor_to_movie: [
    { movieID: 1, actorID: 2 },
    { movieID: 2, actorID: 1 },
    { movieID: 3, actorID: 2 },
    { movieID: 3, actorID: 3 },
    { movieID: 4, actorID: 3 },
    { movieID: 5, actorID: 2 },
  ],
};

var engine = new SQLEngine(movieDatabase);

console.log(engine.execute("SELECT movie.name FROM movie"));
