const rl = require("readline").createInterface(process.stdin, process.stdout);

(async function () {
	var n = await new Promise(res => rl.once("line", res));
	n = parseInt(n);
	var x = await new Promise(res => rl.once("line", res));
	x = x.split(' ').map(Number);
	var ans1 = 0, ans2 = 0, ans3 = 0;
	for(var i = 0; i < n; i++) {
		ans1 += Math.abs(x[i]);
		ans2 += x[i] * x[i];
		ans3 = x[i] > ans3 ? x[i] : ans3;
	}
	console.log(ans1);
	console.log(Math.sqrt(ans2));
	console.log(ans3);
	process.exit();
})();