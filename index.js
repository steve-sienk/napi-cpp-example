const testAddon = require('./build/Release/testaddon.node');
console.log('addon', testAddon);
console.log(testAddon.helloworld());
console.log(testAddon.bye());
module.exports = testAddon;
