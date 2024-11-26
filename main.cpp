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

void write_to_file(string content, string file_name) {
	// Create and open a text file
	ofstream file(file_name);
	
	// Write to the file
	file << content;
	
	// Close the file
	file.close();
}

string merge_files_content(vector<string> &input_files){
	string final_string;
	for (int i = 0; i < input_files.size(); i++){
		string text = get_file_content(input_files[i]);
		final_string += text;
		final_string += "\n";
	}
	return final_string;
	
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

	// Parse the arguments and store input files path in input_files and output file name in output file
	parse_arguments(argc, argv, output_file, input_files);

	// Get the final merged text
	string final_text = merge_files_content(input_files);

	// Write to file
	write_to_file(final_text, output_file);
	
}





























