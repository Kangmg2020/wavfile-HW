#include "waveh.h"



header_struct read_header(ifstream& wavfile) {
	wavfile.seekg(0, wavfile.beg);
	char header_array[44];
	wavfile.read(header_array, 44);
	header_struct header;
	header.ChunkSize = *(int*)(header_array + 4);
	header.SubChunk1Size = *(int*)(header_array + 16);
	header.AudioFormat = *(short*)(header_array + 20);
	header.NumChannels = *(short*)(header_array + 22);
	header.SampleRate = *(int*)(header_array + 24);
	header.ByteRate = *(int*)(header_array + 28);
	header.BlockAlign = *(short*)(header_array + 32);
	header.BitsPerSample = *(short*)(header_array + 34);
	header.SubChunk2Length = *(int*)(header_array + 40);
	for (int i = 0; i < 4; i++) {
		header.ChunkID[i] = header_array[i];
		header.Format[i] = header_array[8 + i];
		header.SubChunk1ID[i] = header_array[12 + i];
		header.SubChunk2ID[i] = header_array[36 + i];
	}
	return header;
}

void print_header(header_struct& header) {
	cout << "ChunkID: " << header.ChunkID[0] << header.ChunkID[1] << header.ChunkID[2] << header.ChunkID[3] << "\n";
	cout << "ChunkSize: " << header.ChunkSize << "\n";
	cout << "Format: " << header.Format[0] << header.Format[1] << header.Format[2] << header.Format[3] << "\n";
	cout << "SubChunkID: " << header.SubChunk1ID[0] << header.SubChunk1ID[1] << header.SubChunk1ID[2] << header.SubChunk1ID[3] << "\n";
	cout << "SubChunk1Size: " << header.SubChunk1Size << "\n";
	cout << "AudioFormat: " << header.AudioFormat << "\n";
	cout << "NumChannels: " << header.NumChannels << "\n";
	cout << "SampleRate: " << header.SampleRate << "\n";
	cout << "ByteRate: " << header.ByteRate << "\n";
	cout << "BlockAlign: " << header.BlockAlign << "\n";
	cout << "BitsPerSample: " << header.BitsPerSample << "\n";
	cout << "SubChunk2ID: " << header.SubChunk2ID[0] << header.SubChunk2ID[1] << header.SubChunk2ID[2] << header.SubChunk2ID[3] << "\n";
	cout << "SubChunk2Length: " << header.SubChunk2Length << "\n";
}

float getfrequency(float hh) {
	float f;
	if (hh == 'G') f = 392.0;
	else if (hh == 'E') f = 329.0;
	else if (hh == 'C') f = 261.0;
	return f;
}
float getAmplitude(float ss) {
	float a;
	a = ss * 1000;
	return a;
}
float getLength(int eumpyo) {
	float T;
	if (eumpyo == 4) T = 1.0;
	else if (eumpyo == 8) T = 0.5;
	else if (eumpyo == 16) T = 0.25; 
	return T;

}

