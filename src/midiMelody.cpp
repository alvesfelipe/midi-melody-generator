#include "midiMelody.h"

MidiMelody::MidiMelody(){}

bool MidiMelody::melodyGenerator(string out_name, string audio_path, string out_path){

	//File archive to handle Python py files
	FILE* file;
	//Get Home FilePath
	char const* auris_aux_home = getenv("AURIS_HOME_PATH");
	string auris_home(auris_aux_home);
	//Variables used by Python.h functions.
	int argc = 4;
	char* argv[argc];
	//Audio Input path
	string audio_p = "" + audio_path; //Get Audio Input Path
	char * audio_path_char = new char[audio_p.size() + 1]; //Create a New Char* Variable
	copy(audio_p.begin(), audio_p.end(), audio_path_char); //Copy from String to Char*
	audio_path_char[audio_p.size()] = '\0';
	//Audio Output path
	string audio_p_output = "" + out_path + out_name + ".mid"; //Get Audio Output Path
	char * audio_p_output_char = new char[audio_p_output.size() + 1]; //Create a New Char* Variable
	copy(audio_p_output.begin(), audio_p_output.end(), audio_p_output_char); //Copy from String to Char*
	audio_p_output_char[audio_p_output.size()] = '\0';
	
	
	Py_SetProgramName((char*)"audio_to_midi_melodia"); //Set Python Archive Name
	Py_Initialize(); //Initialize Python Interpreter

	//Set Python Arguments
	argv[0] = "-W"; //Flag
	argv[1] = audio_path_char; //Audio Imput path
	argv[2] = audio_p_output_char; //Audio Output Path
	argv[3] = "60"; //BPM
	PySys_SetArgv(argc, argv);

	//Open Python file
	string lib_path = "" + auris_home + "/auris-core/midi-melody-generator/lib/audio_to_midi_melodia-master/audio_to_midi_melodia.py"; //Get Python File Path
	const char* path_c = lib_path.c_str(); //Convert from string to const char*
	file = fopen(path_c,"r");
	//If file cannot be found
	if(file == 0){
		cout << "Python Archive Cannot Be Found" << endl;
		return false;
	}

	cout << "Processing..." << endl;
	
    PyRun_SimpleFile(file, "audio_to_midi_melodia.py"); //Run Python Script
    Py_Finalize(); //Finalize Python Interpreter

    return true;
}

MidiMelody::~MidiMelody(){}