#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double calcEntropy(unsigned char* data, const int size)
{
	double ret = 0.0;

	unsigned int hist[256];
	for (int i = 0; i < 256; i++) hist[i] = 0;

	for (int i = 0; i < size; i++)
	{
		hist[data[i]]++;
	}

	double invsize = 1.0 / (double)size;
	for (int i = 0; i < 256; i++)
	{
		const double v = (double)hist[i] * invsize;
		if (v != 0) ret += v*log2(v);
	}

	return -ret;
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Usage:\nentropy.exe input_finename\n");
		return -1;
	}

	FILE* fp = fopen(argv[1], "rb");
	if (fp == NULL)
	{
		fprintf(stderr, "file open error %s\n", argv[1]);
		return -1;
	}

	if (fseek(fp, 0, SEEK_END) != 0)
	{
		fprintf(stderr, "seek error %s\n", argv[1]);
		return -1;
	}

	int file_size = ftell(fp);
	if (file_size == -1)
	{
		fprintf(stderr, "tell error %s\n", argv[1]);
		return -1;
	}

	fseek(fp, 0, SEEK_SET);

	unsigned char* buffer = (unsigned char*)malloc(file_size);
	if (buffer == NULL)
	{
		fprintf(stderr, "malloc error %s\n", argv[1]);
		return -1;
	}

	if (fread(buffer, sizeof(unsigned char), file_size, fp) < file_size)
	{
		fprintf(stderr, "freed error %s\n", argv[1]);
		return -1;
	}

	double entropy = calcEntropy(buffer, file_size);

	printf("file size : %d\n", file_size);
	printf("entropy   : %f\n", entropy);
	printf("ideal size: %f\n", (double)file_size*entropy / 8.0);

	fclose(fp);
	return 0;
}
