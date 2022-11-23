int main()
{
	int n = 0;
	int& r = *&n;
	r = 1; // *&n = 1;
	int& s = *&r;
	s = 2; // *&*&n = 2;
	return 0;
}
