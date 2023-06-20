int rand()
{
	static int sequence[] = {8, 8, 7, 9, 23, 74};
	static int sequenceLength = 5;
	static int currentIndex = 0;
	int nextElement;

	if (currentIndex < sequenceLength)
		nextElement = sequence[currentIndex];
	else
		nextElement = currentIndex * currentIndex % 30000;
	currentIndex++;

	return nextElement;
}
