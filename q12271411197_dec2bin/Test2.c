int main()
{
	// 通常 *& は書かない
	int n = 0;
	*&n = 1;
	*&*&*&*&*&*&*&n = 2;
	return 0;
}
