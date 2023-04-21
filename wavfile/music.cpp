#include "waveh.h"


const float pi = 3.141592;

int main() {
	ifstream letitbe;
	ofstream wavfile;

	letitbe.open("Beatles.wav", ios::binary | ios::in);
	header_struct header = read_header(letitbe);
	print_header(header); // sprint1


	char* data = new char[header.ByteRate * 10];
	header.NumChannels = 1;
	header.ByteRate = header.ByteRate / 2;

	letitbe.read(data, header.ByteRate * 10);
	letitbe.close();
	wavfile.open("my.wav", ios::binary | ios::out);
	if (!wavfile) return 666;
	wavfile.write((char*)&header, 44);
	wavfile.write(data, header.ByteRate * 10);
	wavfile.close(); // sprint 2


	 /*char* data2 = new char[header.ByteRate];

	const float pi = 3.141592;
	float dt = 1. / header.ByteRate, a = 10000.0, f = 440.0;
	for (int i = 0; i < header.ByteRate; i++)
		data2[i] = (char)(a * sin(2.0 * pi * f * i * dt));

	ofstream yy("my.wav", ios::binary | ios::out);
	if (!yy) return 666;
	yy.write((char*)&header, 44);
	yy.write(data2, header.SampleRate);
	yy.close();
}*/
	// sprint 3





	int n;
	int eu;
	int ss;
	char hh;
	char* data3 = new char[header.ByteRate*5];

	ofstream zz("my2.wav", ios::binary | ios::out);
	if (!zz) return 666;
	zz.write((char*)&header, 44);

	ifstream ww("piece.txt");
	ww >> n; 
	for (int i = 0; i < 6; i++) {
		ww >> eu >> hh >> ss;  
		float f = getfrequency(hh);    
		float a = getAmplitude(ss);   
		float T = getLength(eu);
		float dt = 1. / header.ByteRate;
		float playRate = T * header.ByteRate;
		
		for (int I = 0; I < playRate; I++) {
			data3[I] = a * sin(2 * pi * f * I *dt);
		};
		zz.write(data3, playRate);
	}
	zz.close();// sprint 4
}






