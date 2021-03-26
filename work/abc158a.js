inp = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n')
S = inp.shift()
console.log((S == 'AAA' || S == 'BBB') ? "No" : "Yes")