#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

// TO-DO
// implement a merge file function and call read file funtionn in it.
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

string get_file_content(string path) {
	string text_line;
	string full_text;
	ifstream file(path);
	while (getline(file, text_line)){
		full_text += text_line;
		full_text += "\n";
	}
	return full_text;
}

int main(int argc, char *argv[]) {

	string output_file;
	vector<string> input_files;

	string usage = "Usage: \n"
		"\tmergef <file_paths> -o <output_file>";


	if (argc < 4 || argv[1] == "-h" || argv[1] == "--help") {
		cout << usage << endl;
		return 0;
	}
	parse_arguments(argc, argv, output_file, input_files);

	for (int i = 0; i < input_files.size(); i++){
		string text = get_file_content(input_files[i]);
		cout << text << endl;
	}
	
}





























