int rand()
{
	static int counter = 0;

	counter++;
	if (counter == 1)
		return 8;
	if (counter == 2)
		return 8;
	if (counter == 3)
		return 7;
	if (counter == 4)
		return 9;
	if (counter == 5)
		return 23;
	if (counter == 6)
		return 74;
	return counter * counter % 30000;
}