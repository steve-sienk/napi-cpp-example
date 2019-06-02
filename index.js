const testAddon = require('./build/Release/testaddon.node');
console.log('addon', testAddon);
console.log(testAddon.helloworld());
console.log(testAddon.bye());
console.log(testAddon.add(1111, 2222));

const myPandas = new testAddon.MyAwesomeClass("Andy Panda");
console.log("Initial bamboo: ", myPandas.bamboo());
console.log("After adding another panda: ", myPandas.append("Bei Bei"));
myPandas.append("Basi");
console.log("And a third: ", myPandas.bamboo());

module.exports = testAddon;
