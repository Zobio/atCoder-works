template<typename T>
T nCr(T n, T r) {
	T ret = 1;
	for(T i = 0; i < r; i++) {
		ret *= n - i;
		ret /= i + 1;
	}
	return ret;
}