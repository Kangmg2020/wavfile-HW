#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct header_struct {
	char ChunkID[4];
	int ChunkSize;
	char Format[4];
	char SubChunk1ID[4];
	int SubChunk1Size;
	short AudioFormat;
	short NumChannels;
	int SampleRate;
	int ByteRate;
	short BlockAlign;
	short BitsPerSample;
	char SubChunk2ID[4];
	int SubChunk2Length;
};
header_struct read_header(ifstream& wavfile);
void print_header(header_struct& header);
char* read_data(header_struct& header, ifstream& wavfile, int nsamples, int skip);

float getfrequency(float hh);
float getAmplitude(float ss);
float getLength(int eumpyo);


