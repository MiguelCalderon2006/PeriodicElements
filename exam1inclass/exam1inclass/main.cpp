//Miguel Calderon
//4-4-24
//CMPR-121 Exam 1 periodic table profesor Quach
#include <windows.h>
#include <iostream>
#include <iomanip>
#include "input.h"
#include<fstream>
#include <vector> 

using namespace std;
char menuOption();
void binary();//advanced binary file operations option
void dynamic();//Dynamic Allocated Array option
void vectors();//Vector Option

//structure contains attributes of each element
struct Element
{
	int atomicNumber = 0;
	double atomicMass = 0.0;
	char symbol[3] = "**";
	char name[25] = "unkown";
	int standardState = 0;
	int chemicalGroup = 0;
	double meltingPoint = 0.0;
	double boilingPoint = 0.0;
	int yearDiscovered = 0;
	char discoverer[100] = "unkown";

};
const string state[] = { "unknown",  "Gas","Liquid","Solid" };
const string block[] = { "unknown",  " Nonmetal" , "Nobel Gas", "Alkali Metal", "Alkaline Earth Metal",  "Transition Metal",  "Post-Transition Metal", "Metalloid",  "Halogen", "Lanthanide","Actinide" };
const int ELEMENT_SIZE = 118;

//pre condition: degrees in kelvin (double variable)
//post condition: returns Celsius converted double variable
double kelvinToCelsius(double kelvin)
{
	return kelvin - 273.15;
}

//pre condition:a variable of the data type Element
//post condition:attributes of the element is displayed
void displayElement(const Element e)
{
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tAtomic Number" << "                     " << ": " << e.atomicNumber;
	cout << "\n\tSymbol" << "                            " << ": " << e.symbol;
	cout << "\n\tName" << "                              " << ": " << e.name;
	cout << "\n\tAtomic Mass" << "                       " << ": " << fixed << setprecision(4) << e.atomicMass << " u";
	cout << "\n\tChemical Group Block" << "              " << ": " << block[e.chemicalGroup];
	cout << "\n\tStandard State" << "                    " << ": " << state[e.standardState];
	cout << "\n\tMelting Point" << "                     " << ": " << fixed << setprecision(2) << kelvinToCelsius(e.meltingPoint) << char(167) << "C" << " (" << e.meltingPoint << " K)";
	cout << "\n\tBoiling Point" << "                     " << ": " << fixed << setprecision(2) << kelvinToCelsius(e.boilingPoint) << char(167) << "C" << " (" << e.boilingPoint << " K)";
	cout << "\n\tYear Discovered" << "                   " << ": " << e.yearDiscovered;
	cout << "\n\tDiscovered by" << "                     " << ": " << e.discoverer;


}

//main menu with the 3 options
int main()
{
	do
	{
		switch (tolower(menuOption()))
		{
		case 'x':exit(0); break;
		case 'a':binary(); break;
		case 'b':dynamic(); break;
		case 'c':vectors(); break;
		}
		system("pause");
	} while (true);
	return 0;
}

//displays elemenmt symbol table colored
void displayElementTable()
{
	cout << "\n\n\t\t\tPERIODIC TABLE OF ELEMENTS BY SYMBOL\n";
	cout << "\033[93m\n\t[  H]" << string(80, ' ') << "\033[91m[ He]";
	cout << "\n\t\033[36m[ Li]\033[31m[ Be]" << string(50, ' ') << "\033[94m[  B]\033[93m[  C][  N][  O]\033[37m[  F]\033[91m[ Ne]";
	cout << "\n\t\033[36m[ Na]\033[31m[ Mg]" << string(50, ' ') << "\033[32m[ Al]\033[94m[ Si]\033[93m[  P][  S]\033[37m[ Cl]\033[91m[ Ar]";
	cout << "\n\t\033[36m[  K]\033[31m[ Ca]\033[95m[ Sc][ Ti][  V][ Cr][ Mn][ Fe][ Co][ Ni][ Cu][ Zn][ Ga]\033[94m[ Ge][ As]\033[93m[ Se]\033[37m[ Br]\033[91m[ Kr]";
	cout << "\n\t\033[36m[ Rb]\033[31m[ Sr]\033[95m[  Y][ Zr][ Nb][ Mo][ Tc][ Ru][ Rh][ Pd][ Ag][ Cd][ In][ Sn]\033[94m[ Sb][ Te]\033[37m[  I]\033[91m[ Xe]";
	cout << "\n\t\033[36m[ Cs]\033[31m[ Ba]  *  \033[95m[ Hf][ Ta][  W][ Re][ Os][ Ir][ Pt][ Au][ Hg]\033[32m[ Tl][ Pb][ Bi][ Po][ At]\033[91m[ Rn]";
	cout << "\n\t\033[36m[ Fr]\033[31m[ Ra]  ** \033[95m[ Rf][ Db][ Sg][ Bh][ Hs]\033[90m[ Mt][ Ds][ Rg][ Cn][ Nh][ Fl][ Mc][ Lv][ Ts][ Og]";
	cout << "\n\t\t";
	cout << "\n\t\t    " << "\033[0m" << "*  \033[94m[ La][ Ce][ Pr][ Nd][ Pm][ Sm][ Eu][ Gd][ Tb][ Dy][ Ho][ Er][ Tm][ Yb][ Lu]";
	cout << "\n\t\t    " << "\033[0m" << "** \033[33m[ Ac][ Th][ Pa][  U][ Np][ Pu][ Am][ Cm][ Bk][ Cf][ Es][ Fm][ Md][ No][ Lr]";

	cout << "\033[0m\n\n";


}

//displays element table with atomic number instead also colored
void displayAtomicTable()
{
	cout << "\n\n\t\t\tPERIODIC TABLE OF ELEMENTS BY ATOMIC NUMBER (for color - 5 pts Xtra)\n";
	cout << "\033[93m\n\t[  1]" << string(80, ' ') << "\033[91m[  2]";
	cout << "\n\t\033[36m[ 3 ]\033[31m[ 4 ]" << string(50, ' ') << "\033[94m[ 5 ]\033[93m[  6][  7][  8]\033[37m[  9]\033[91m[ 10]";
	cout << "\n\t\033[36m[ 11]\033[31m[ 12]" << string(50, ' ') << "\033[32m[ 13]\033[94m[ 14]\033[93m[ 15][ 16]\033[37m[ 17]\033[91m[ 18]";
	cout << "\n\t\033[36m[ 19]\033[31m[ 20]\033[95m[ 21][ 22][ 23][ 24][ 25][ 26][ 27][ 28][ 29][ 30][ 31]\033[94m[ 32][ 33]\033[93m[ 34]\033[37m[ 35]\033[91m[ 36]";
	cout << "\n\t\033[36m[ 37]\033[31m[ 38]\033[95m[ 39][ 40][ 41][ 42][ 43][ 44][ 45][ 46][ 47][ 48][ 49][ 50]\033[94m[ 51][ 52]\033[37m[ 53]\033[91m[ 54]";
	cout << "\n\t\033[36m[ 55]\033[31m[ 56]  *  \033[95m[ 72][ 73][ 74][ 75][ 76][ 77][ 78][ 79][ 80]\033[32m[ 81][ 82][ 83][ 84][ 85]\033[91m[ 86]";
	cout << "\n\t\033[36m[ 87]\033[31m[ 88]  ** \033[95m[104][105][106][107][108]\033[90m[109][110][111][112][113][114][115][116][117][118]";
	cout << "\n\t\t";
	cout << "\n\t\t    " << "\033[0m" << "*  \033[94m[ 57][ 58][ 59][ 60][ 61][ 62][ 63][ 64][ 65][ 66][ 67][ 68][ 69][ 70][ 71]";
	cout << "\n\t\t    " << "\033[0m" << "** \033[33m[ 89][ 90][ 91][ 92][ 93][ 94][ 95][ 96][ 97][ 98][ 99][100][101][102][103]";

	cout << "\033[0m";



}

//returns main menu option
char menuOption()
{
	system("cls");

	displayElementTable();
	cout << "\n\n\tThe periodic table, also known as the periodic table of the elements, arranges the chemical\n"
		"\telements into rows and columns. It is an organizing icon of chemistry and is widely used in\n"
		"\tphysics and other sciences. It's a depiction of the periodic law, which says that when the\n"
		"\telements are arranged in order of their atomic numbers an approximate recurrence of\n"
		"\ttheir properties is evident.\n";

	cout << "\n\n\tCMPR121: Exam#1 - Periodic Table of Elements by Miguel Calderon (4/3/2024)";
	cout << "\n\t" << string(91, char(205));

	cout << "\n\tA. Advanced Binary File Operations (chapter 12 -50 pts)";
	cout << "\n\tB. Dynamic Allocated Array        (chapter  9 - 25 pts)";
	cout << "\n\tC. Vector(array)                  (chapter  7 -25 pts)";
	cout << "\n\t" << string(91, char(196));
	cout << "\n\tX. Exit";
	cout << "\n\t" << string(91, char(205));
	return inputChar("\n\tOption: ", true);
	cout << "\033[0m";

}

//temporary display when user choses to edit an element
void displayElementTemps(Element temp )
{
	cout << "\n\t" << string(70, char(196));
	cout << "\n\tAtomic Number" << "                     " << ": " << temp.atomicNumber;
	cout << "\n\tSymbol" << "                            " << ": " << temp.symbol;
	cout << "\n\tName" << "                              " << ": " << temp.name;
	cout << "\n\tAtomic Mass" << "                       " << ": " << fixed << setprecision(4) << temp.atomicMass << " u";
	cout << "\n\tChemical Group Block" << "              " << ": " << block[temp.chemicalGroup];
	cout << "\n\tStandard State" << "                    " << ": " << state[temp.standardState];
	cout << "\n\tMelting Point" << "                     " << ": " << fixed << setprecision(2) << kelvinToCelsius(temp.meltingPoint) << char(167) << "C" << " (" << temp.meltingPoint << " K)";
	cout << "\n\tBoiling Point" << "                     " << ": " << fixed << setprecision(2) << kelvinToCelsius(temp.boilingPoint) << char(167) << "C" << " (" << temp.boilingPoint << " K)";
	cout << "\n\tYear Discovered" << "                   " << ": " << temp.yearDiscovered;
	cout << "\n\tDiscovered by" << "                     " << ": " << temp.discoverer;
}

//pre condition: a variable of the Element data type and filename
//post condition:changes attributes based on user inputs
void editElement(Element& e, string filename)
{
	Element temp = e;
	do {
		system("cls");
		displayElementTemps(temp);
		cout << "\n\n\tEdit Element Properties Menu";
		cout << "\n\t" << string(91, char(205));
		cout << "\n\t  1. Atomic Number";
		cout << "\n\t  2. Symbol";
		cout << "\n\t  3. Name";
		cout << "\n\t  4. Atomic Mass";
		cout << "\n\t  5. Chemical Group Block";
		cout << "\n\t  6. Standard State";
		cout << "\n\t  7. Melting Point";
		cout << "\n\t  8. Boiling Point";
		cout << "\n\t  9. Discovered Year";
		cout << "\n\t 10. Discovered By";
		cout << "\n\t" << string(91, char(196));
		cout << "\n\t -1. return without committing the updates";
		cout << "\n\t  0. Committing the updates and return";
		cout << "\n\t" << string(91, char(205));		int option = inputInteger("\n\n\tOption: ", -1, 10);
		switch (option)
		{
		case -1:
		{
			cout << "\n\tElement has NOT been edited / updated into the binary file, " << filename << ".";

			return;
		}
		case 0:
		{
			e = temp;
			cout << "\n\tElement has been edited / updated into the binary file, " << filename << ".";
			return;
		}
		case 1:temp.atomicNumber = inputInteger("\n\tEnter an Atomic Number: ", 1, 118); break;

		case 2: {
			string symbolInput = inputString("\n\tEnter the symbol: ", true);
			if (symbolInput.length() > 2) {
				symbolInput = symbolInput.substr(0, 2); // Truncate
			}
			strcpy_s(temp.symbol, sizeof(temp.symbol), symbolInput.c_str());
		}break;

		case 3:
		{
			string nameInput = inputString("\n\tEnter the name: ", true);
			if (nameInput.length() > 24) {
				nameInput = nameInput.substr(0, 24);
			}
			strcpy_s(temp.name, sizeof(temp.name), nameInput.c_str());
		}break;

		case 4:temp.atomicMass = inputDouble("\n\tEnter the Atomic Mass (u): ", true); break;

		case 5:temp.chemicalGroup = inputInteger("\n\tEnter the Chemical Group Block (0 - unknown, 1 - Nonmetal, 2 - Noble Gas, 3 - Alkali Metal, 4 - Alkaline Earth Metal, 5 - Post-transition Metal, 6 - Metalloid, 7 - Halogen, 8 - Nonmetal, 9 - Lanthanide, or 10 - Actinide) : ", 0, 10); break;

		case 6:temp.standardState = inputInteger("\n\tEnter the Standard State(0 - unknown, 1 - Gas, 2 - Liquid, or 3 - Solid) : ", 0, 3); break;

		case 7:temp.meltingPoint = inputInteger("\n\tEnter the Melting Point (K): ", true); break;

		case 8:temp.boilingPoint = inputInteger("\n\tEnter the Boiling Point (K): ", true); break;

		case 9:temp.yearDiscovered = inputInteger("\n\tEnter the Year Discovered: ", true); break;

		case 10:
		{
			string discovererInput = inputString("\n\tEnter the Discoverer(s): ", true);
			if (discovererInput.length() > 99) {
				discovererInput = discovererInput.substr(0, 99); // Truncate
			}
			strcpy_s(temp.discoverer, sizeof(temp.discoverer), discovererInput.c_str());
		} break;

		}
	} while (true);
}

//Option A  Advanced Binary File Operations
void binary()
{
	fstream file;
	string filename = "UKNOWN";
	do
	{
		system("cls");
		displayElementTable();//dispalys the periodic table
		cout << "\n\tAdvanced Binary File Operations Menu";
		cout << "\n\t" << string(91, char(205));
		cout << "\n\t1. Read and Display ALL elements from binary data file";
		cout << "\n\t2. Search and update an element by Symbol from binary file";

		cout << "\n\t" << string(91, char(196));
		cout << "\n\t0. Return to main menu";
		cout << "\n\t" << string(91, char(205));
		int option = inputInteger("\n\tOption: ", 0, 2);
		Element element;

		switch (option)
		{
		case 0:
		{

			if (file.is_open())
			{
				file.close();
			} return;
		}
		case 1:
		{
			//asks for filename and attempts to open it
			filename = inputString("\n\tEnter the binary data file name(unsorted.dat): ", true);
			file.open(filename, ios::in | ios::binary);
			if (file.fail())
			{
				cout << "\n\tERROR: Binary file, " << filename << ", cannot be found"; break;
			}


			file.seekg(0, ios::end);//moves to end of file
			file.seekg(0, ios::beg);//moves to begining

			for (int i = 0; i < ELEMENT_SIZE; i++)
			{
				file.read(reinterpret_cast<char*>(&element), sizeof(Element));//read element
				cout << "\n\n\tElement (struct) #" << i + 1 << " - " << sizeof(element) << " Bytes";
				displayElement(element);//display element
			}
			file.close();



		}break;

		case 2:
		{
			//attmpts to open file
			file.open(filename, ios::in | ios::out | ios::binary);
			if (file.fail())
			{
				cout << "\n\tERROR: Binary file, " << filename << ".dat , cannot be found"; break;
			}

			file.seekg(0, ios::end);//moves to end of file
			file.seekg(0, ios::beg);//moves to begining



			string searchSymbol = inputString("\n\tEnter an Element Symbol to be searched and updated: ", true);

			bool found = false;//bool if user inpit is found
			for (int i = 0; i < ELEMENT_SIZE; i++)
			{
				file.read(reinterpret_cast<char*>(&element), sizeof(Element));//reads
				if (strcmp(searchSymbol.c_str(), element.symbol) == 0)//llooks for and compares
				{
					found = true;
					displayElement(element);//display element table
					editElement(element, filename);//edit the elements
					file.seekp(i * sizeof(Element));
					file.write(reinterpret_cast<char*>(&element), sizeof(Element));//applies changes to file
					break;
				}

			}

			if (!found)
			{
				cout << "\n\tERROR: Element Symbol was not found in, " << filename;
				file.close();
				break;
			}



			file.close();

		}break;

		}


		cout << "\n\n";
		system("pause");
	} while (true);
}


//option B Dynamic Allocated Array 
void dynamic() {
	Element* array = new Element[ELEMENT_SIZE];
	string filename="UNKOWN";
	bool arrayLoaded = false;

	do {
		system("cls");
		displayAtomicTable();
		cout << "\n\tDynamic Allocated Array Menu";
		cout << "\n\t" << string(91, char(205));
		cout << "\n\t1. Read, store ALL elements from binary file into the sorted array";
		cout << "\n\t2. Display ALL elements from the array";
		cout << "\n\t3. Search and update an element by Atomic Number from the array";
		cout << "\n\t4. Write ALL elements from the array into the binary file";
		cout << "\n\t" << string(91, char(196));
		cout << "\n\t0. Return to main menu";
		cout << "\n\t" << string(91, char(205));
		int option = inputInteger("\n\tOption: ", 0, 4);

		switch (option) {
		case 0: {
			//dealocates memory
			delete[] array;
			array = nullptr;
			return;
		}
		case 1: {
			//user input
			filename = inputString("\n\tEnter a binary data file (unsorted.dat): ", false);
			fstream inputfile(filename, ios::in | ios::binary);
			if (!inputfile) {
				cout << "\n\tERROR: Binary data file, " << filename << ", cannot be found.";
				break;
			}

			//reads file into an array
			for (int i = 0; i < ELEMENT_SIZE; i++) {
				inputfile.read(reinterpret_cast<char*>(&array[i]), sizeof(Element));
			}
			inputfile.close();

			// Sorting the array (selection sort)
			for (int i = 0; i < ELEMENT_SIZE - 1; i++) {
				for (int j = 0; j < ELEMENT_SIZE - i - 1; j++) {
					if (array[j].atomicNumber > array[j + 1].atomicNumber) {
						Element temp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = temp;
					}
				}
			}

			cout << "\n\tSUCCESS: read binary data from file"<<filename<<"Data has been read into the dynamic array and sorted.";
			arrayLoaded = true;
			break;
		}
		case 2: {
			//validates input
			if (!arrayLoaded) {
				cout << "\n\tERROR: Array is empty complete step 1 first!!"; break;
				break;
			}
			//displays the dynamicly allocated array
			for (int i = 0; i < ELEMENT_SIZE; i++) {
				cout << "\n\n\tElement #" << i + 1 << " - " << sizeof(array[i]) << " Bytes";
				displayElement(array[i]);
			}
			break;
		}
		case 3: {
			//validates input
			if (!arrayLoaded) {
				cout << "\n\tERROR: Array not loaded. Please read data into the array first!";
				break;
			}
			//user input
			int atomicNum = inputInteger("\n\tEnter an Atomic Number (1...118) to search and update: ", 1, 118);
			bool found = false;

			//searches for matching atomic number and prompts user changes to make
			for (int i = 0; i < ELEMENT_SIZE; i++) {
				if (array[i].atomicNumber == atomicNum) {
					displayElement(array[i]); //dispalys element itseld with attributes
					editElement(array[i], filename);//user edits element
					found = true;
					break;
				}
			}
			//validation
			if (!found) {
				cout << "\n\tERROR: Element with atomic number " << atomicNum << " not found.";
			}
			break;
		}
		case 4: {
			//validation
			if (!arrayLoaded) {
				cout << "\n\tERROR: Array not loaded. Please read data into the array first.";
				break;
			}
			//lets user save array into a file
			filename = inputString("\n\tEnter a binary filename to save: ", false);
			fstream outputfile(filename, ios::out | ios::binary);
			if (!outputfile) {
				cout << "\n\tERROR: Failed to open the output file!";
				break;
			}
			//writes array into new file
			for (int i = 0; i < ELEMENT_SIZE; i++) {
				outputfile.write(reinterpret_cast<char*>(&array[i]), sizeof(Element));
			}
			outputfile.close();
			cout << "\n\tSUCCESS: Elements have been successfully written to: " << filename;
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
}


//option C Vector

void vectors() {
	vector<Element> array;
	string filename = "";
	bool vectorLoaded = false;

	do {
		system("cls");
		displayAtomicTable();
		cout << "\n\tVector array Menu";
		cout << "\n\t" << string(91, char(205));

		cout << "\n\t1. Read and store ALL elements from binary file into the unsorted vector (array)";
		cout << "\n\t2. Display ALL elements from the vector";
		cout << "\n\t3. Search and update an element by Name from the vector";
		cout << "\n\t4. Write ALL elements from the vector into the binary file";
		cout << "\n\t" << string(91, char(196));
		cout << "\n\t0. Return to main menu";
		cout << "\n\t" << string(91, char(205));

		int option = inputInteger("\n\tOption: ", 0, 4);
		fstream file;

		switch (option) {
		case 0:
			return;
		case 1: {
			//asking for user input of binary file
			filename = inputString("\n\tEnter the binary data file name (unsorted.dat): ", true);
			file.open(filename, ios::in | ios::binary);
			//validation
			if (!file) {
				cout << "\n\tERROR: Binary file, " << filename << ", cannot be found.";
				break;
			}

			//reads file into vector
			Element temp;
			while (file.read(reinterpret_cast<char*>(&temp), sizeof(Element))) {
				array.push_back(temp);
			}
			file.close();

			vectorLoaded = true;
			cout << "\n\tSUCCESS: read binary data from the file, "<<filename;
				cout<<"\n\tElements have been loaded into the vector.";
			break;
		}
		case 2: {
			//validation
			if (!vectorLoaded) {
				cout << "\n\tERROR: Vector is empty. Complete step 1 first!";
				break;
			}
			//dispalays all the elements
			for (const auto& element : array) {
				displayElement(element);
			}
			break;
		}
		case 3: {
			//validation
			if (!vectorLoaded) {
				cout << "\n\tERROR: Vector is empty. Complete step 1 first!";
				break;
			}
			//user input for element name
			string searchName = inputString("\n\tEnter an Element Name to be searched and updated: ", true);
			bool found = false;

			//allows user to edit attributes
			for (auto& element : array) {
				if (searchName == element.name) {//searches for match
					displayElement(element);//menu of element attributes
					editElement(element, filename);//allows user to edit
					found = true;
					break;
				}
			}
			if (!found) {
				cout << "\n\tERROR: Element Name, " << searchName << ", was not found.";
			}
			break;
		}
		case 4: {
			//validation
			if (!vectorLoaded) {
				cout << "\n\tERROR: Vector is empty. Complete step 1 first!";
				break;
			}
			//asks for binary file name to save vector into
			filename = inputString("\n\tEnter a binary filename to save: ", true);
			file.open(filename, ios::out | ios::binary);
			if (!file) {
				cout << "\n\tERROR: Failed to open the output file.";
				break;
			}
			//writes in the vector into the file
			for (const auto& element : array) {
				file.write(reinterpret_cast<const char*>(&element), sizeof(Element));
			}
			file.close();
			cout << "\n\tSUCCESS: Elements have been successfully written to: " << filename;
			break;
		}
		}
		cout << "\n\n";
		system("pause");
	} while (true);
}
