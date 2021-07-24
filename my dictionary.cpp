#include<bits/stdc++.h>
using namespace std ; 
// structure of TrieNode
class TrieNode 
{
    public:
	string meaning ; 
	bool isEnd ; 
	TrieNode * children[26]; 
	TrieNode ()
	{
		isEnd = false ; 
		for(int i = 0;i<26;i ++) // let character in a word lies from a-z only 
		{
			children[i]=NULL ; 
		}
	}
};
class Dictionary // class Dictionary
{
	TrieNode * root ;
	public : 
	Dictionary() // constructor
	{
		root = new TrieNode (); 
	}
	void insert ( string word , string meaning ) // insert the word and its meaning in Dictionary
	{
		
		int n = word.length() ; 
		TrieNode * temp = root ; 
		for (int i = 0 ; i < n ; i ++ )
		{
			int index = word [ i ] - 'a' ; 
			if ( temp -> children [ index ] == NULL )
			{
				temp -> children [ index ] = new TrieNode () ; 
			}
			temp = temp -> children [ index ] ; 
				
		}
		temp -> isEnd = true ;
		temp -> meaning = meaning ; 
	}
	
	TrieNode * search ( string word ) // search if the word is present or not
	{
		
		int n = word.length() ; 
		TrieNode * temp = root ; 
		for (int i = 0 ; i < n ; i ++ )
		{
			int index = word [ i ] - 'a' ; 
			if ( temp -> children [ index ] == NULL )
			{
				return NULL ; 
			}
			temp = temp -> children [ index ] ; 
		}	
		if ( temp -> isEnd)
		{
			return temp ; 
		}
		return NULL; 
	}
	
	string FindMeaning ( string word  ) // find the meaning of the word
	{
		TrieNode *temp = search ( word ) ; 
		if ( !temp ) 
		{
			return "Word Does not Exit" ; 
		}
		else 
			return temp -> meaning ; 
	}
	
	bool IsEmpty( TrieNode * root )
	{
		for ( int i = 0 ; i < 26 ; i ++  ) 
		{
			if ( root -> children [ i ] ) 
			{
				return 0 ; 
			}
		}		
		return 1 ; 
	}
	
	TrieNode * Delete_word ( TrieNode * root , string s, int n , int depth  ) // to delete the word from the Dictionary
	{
		if (root==NULL) 
		{
			return NULL;
		} 
		
		if ( depth == n ) 
		{
			if ( root -> isEnd ) 
			{
				root -> isEnd = 0 ; 
			}
			
			if ( IsEmpty( root )) 
			{
				delete (root ) ; 
				return NULL ; 
			}
			
			return root ; 
		}
		
		int index = s [ depth] - 'a' ; 
		
		root -> children [ index ] = Delete_word ( root -> children [ index ] , s , n , depth + 1 ) ; 
		
		if ( IsEmpty( root ) and root -> isEnd == 0 ) 
		{
			delete (root ) ; 
			return NULL ; 
		}
		return root ; 
	}	
	
	void  Delete ( string word ) 
	{
	 	TrieNode * temp = search (word) ; 
		if ( temp==NULL) 
			return ; 
		else 
			Delete_word( root , word ,word.length() , 0 ) ; 
	}
};
	
	
int main()
{ 
    // user interface
	Dictionary d;
	int flag;
	do
	{
	    int ch;
	    flag=0;
	    cout<<"\nEnter 1: To insert the word and its meaning";
	    cout<<"\nEnter 2: To find the meaning of the word";
	    cout<<"\nEnter 3: To delete the word";
	    cout<<"\nEnter 4: To Exit";
	    cout<<"\nEnter your choice:: ";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:{
    	                string word;
    	                string meaning;
    	                cout<<"\nEnter the word:: ";
    	                cin>>word;
    	                cout<<"\nEnter the meaning of the "<<word<<":: ";
    	                cin>>meaning;
    	                d.insert(word,meaning);
	                } 
	               break;
	         case 2:
	               {
    	                string word;
    	                cout<<"\nEnter the word:: ";
    	                cin>>word;
    	                if(d.search(word)==NULL)
    	                {
    	                    cout<<"\nword is not present";
    	                }
    	                else
    	                {   
    	                    cout<<"\nThe meaning of the word is:: "<<d.FindMeaning(word);
    	                }
	               }
	                break;
	         case 3:
	               {
    	               string word;
    	               cout<<"\nEnter the word:: ";
    	               cin>>word;
    	               if(d.search(word)==NULL)
    	               {
    	                    cout<<"\nword is not present";
    	               }
    	               else
    	               {   
    	                   cout<<"\nword is deleted";
    	                   d.Delete ( word ) ; 
    	               }
	               }
	               break;
	         case 4:
    	            {
    	               cout<<"\n\t\t------EXIT---------";
    	               cout<<"\n\t\t----welcome----";
    	               flag=1;
    	            }
	               break;
	         default:
	               cout<<"Wrong no enter";
	               break;
	    }
	    
	}while(flag==0);
	return 0;
}
