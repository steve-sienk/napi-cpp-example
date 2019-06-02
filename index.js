const testAddon = require('./build/Release/testaddon.node');
console.log('addon', testAddon);
console.log(testAddon.helloworld());
console.log(testAddon.bye());
console.log(testAddon.add(1111, 2222));
module.exports = testAddon;
