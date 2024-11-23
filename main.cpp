#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void parse_arguments(int argc, char* argv[], string &output_file, vector<string> &input_files){
	for (int i = 1; i < argc; i++){
		string arg = argv[i];
		
		if (arg == "-o"){
			output_file = argv[++i];
		} else {
			input_files.push_back(arg);
		}

	}
}

int main(int argc, char *argv[]) {

	string output_file;
	vector<string> input_files;
	parse_arguments(argc, argv, output_file, input_files);
	
	for (int i = 0; i < input_files.size(); i++){
		string text_line;
		string full_text;
		ifstream file(input_files[i]);

		while (getline(file, text_line)){
			full_text += text_line;
			full_text += "\n";
		}
		cout << full_text<<endl;
	}

}

