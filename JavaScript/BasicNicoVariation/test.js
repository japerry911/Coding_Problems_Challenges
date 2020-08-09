const nico = require('./index');

test('nico is a function', () => {
    expect(typeof nico).toEqual('function');
});

test('Encrypts secretinformation with crazy as a key', () => {
    expect(nico('crazy', 'secretinformation')).toEqual('cseerntiofarmit on  ');
});

test('Encrypts abcd with abc as a key', () => {
    expect(nico('abc', 'abcd')).toEqual('abcd  ');
});

test('Encrypts 1234567890 with ba as a key', () => {
    expect(nico('ba', '1234567890')).toEqual('2143658709');
});

test('Encrypts message with a as a key', () => {
    expect(nico('a', 'message')).toEqual('message');
});

test('Encrypts key with key as a key', () => {
    expect(nico('key', 'key')).toEqual('eky');
});