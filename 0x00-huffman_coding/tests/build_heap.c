build-max-heap(arr)
{
	n = length of arr;
	for (i = n/2; i > 0; i--)
	{
		max-heapify(arr, i);
	}

}