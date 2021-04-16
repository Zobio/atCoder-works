function main(input) {
	input = input.split('\n');
	const n = Number(input[0]);
	const x = input[1].split(' ').map(Number).map(Math.abs);
}

main(require('fs').readFileSync('/dev/stdin', 'utf8').trim());