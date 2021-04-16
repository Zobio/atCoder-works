function main(input) {
	input = input.split('\n');
	let n = input[0];
	let x = input[1].split(' ').map(Number).map(Math.abs);
	for(let i = 0; i < x.length; i++) {
		console.log(x[i]);
	}
}

main(require('fs').readFileSync('/dev/stdin', 'utf8').trim());