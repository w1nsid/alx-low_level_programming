int rand()
{
	static int currentElementIndex = 0;
	int sequence[] = {8, 8, 7, 9, 23, 24};
	int sequenceLength = sizeof(sequence) / sizeof(sequence[0]);

	int nextElement = sequence[currentElementIndex];

	currentElementIndex = (currentElementIndex + 1) % sequenceLength;

	return nextElement;
}
