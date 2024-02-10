        else{
                        swap(arr,i,j);
                                    i++;
                                                j++;
                                                        }
                                                            }
                                                                return j-1;
                                                                }

                                                                void quickSort(string arr[], int low, int high){
                                                                    if(low < high){
                                                                        string pivot = arr[high];
                                                                            int pos = partition(arr, low, high, pivot);
                                                                                
                                                                                    quickSort(arr, low, pos-1);
                                                                                        quickSort(arr, pos+1, high);
                                                                                            }
                                                                                            }
                                                                                            int main()
                                                                                            {
                                                                                                ifstream f;
                                                                                                    f.open(FILENAME);
                                                                                                        if ( f.fail() ) { cout << "Il file di input non esiste"; return -1; }
                                                                                                            
                                                                                                                // legge tutto il file per misurarne il numero di righe
                                                                                                                    int n;
                                                                                                                        string s;
                                                                                                                            for (n=0; getline(f,s); n++);
                                                                                                                                f.close();
                                                                                                                                    cout << "il file di input contiene " << n << " righe" << endl;
                                                                                                                                        
                                                                                                                                            // rilegge il file per caricarne le righe in un vettore
                                                                                                                                                string vs[n];
                                                                                                                                                    f.open(FILENAME);
                                                                                                                                                        for (int i=0; i<n; i++) getline( f, vs[i] );

                                                                                                                                                            stampaVettore(vs, n);
                                                                                                                                                                numeroScambi=0;
                                                                                                                                                                    cout<<"Vuoi che ti riordini il vettore con quickSort(se si scrivi qs) o con bubbleSoft(se si scrivi bS)";
                                                                                                                                                                        int ris;
                                                                                                                                                                            if(ris==qs)
                                                                                                                                                                                //quickSort(vs,0,n-1);
                                                                                                                                                                                    numeroScambi=bubbleSort(vs,n);
                                                                                                                                                                                        cout << "Eseguiti " << numeroScambi << " scambi." << endl;
                                                                                                                                                                                            stampaVettore(vs, n);

                                                                                                                                                                                                return 0;
                                                                                                                                                                                                v
        }

                                                        

                                                                                                                        