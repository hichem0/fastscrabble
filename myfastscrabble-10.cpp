#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main( int argc, char *argv[]) {

    string dictionary_name;
    bool found = 1;
    multiset<string> result;

    ///// Checker command /////

    if ( (argc < 5) || (string(argv[1]) != "-d") || (argv[2]==NULL) 
	|| (string(argv[3]) != "-s") || (argv[4]==NULL) ) // au moins 5 args
    {
	cout << "commande invalide "<<endl;
	return 2;
	
    }else {

	for(int i=5; i<argc; i=i+2)
		{
		   if( string(argv[i]) != "-s" || argv[i+1]==NULL)
			{
				cout << "commande invalide"<< endl;
				return 2;			
			}		
		}
	  }

	// ouvrir dic.txt
    dictionary_name = argv[2];
    ifstream ifs(dictionary_name);

 // vérifier si dic.txt est correctement ouvert
    if (!ifs.is_open()){
        //cout << "Cannot open file\n";
        return 3;
    }

///// mapper le fichier dic.txt dans une multimap/////
    multimap<string, string> dic_map;
    string word;
    string sorted_word;

    while (ifs >> word) {
        sorted_word = word;
        transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
	sort(sorted_word.begin(), sorted_word.end());
        dic_map.insert(pair<string,string>(sorted_word,word));
    }
    ifs.close();

	    // Rechercher les anagrammes

    for (int i = 4; i<argc; i=i+2)
    {
       
            string actual_word = argv[i];
            string sorted_word = actual_word;
            transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
            sort(sorted_word.begin(), sorted_word.end());

            pair <multimap<string,string>::iterator, multimap<string,string>::iterator> find;
            find = dic_map.equal_range(sorted_word);

	//Insérer le résultat de la recherche dans un ensemble
                for (auto it = find.first; it != find.second; it++)
                {
                    result.insert(it->second);
                    found = 0;
                }    
    }
	// print results

    for(auto &setval :result)
    {
        cout << setval << endl;
    }
	//cout << result.size();

    return found;
}

