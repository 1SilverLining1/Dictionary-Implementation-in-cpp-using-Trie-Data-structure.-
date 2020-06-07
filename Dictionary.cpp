#include<bits/stdc++.h>
using namespace std ; 

struct TrieNode 
{
	string meaning ; 
	bool isEnd ; 
	TrieNode * children [ 26] ; 
	
	public : 
	
	TrieNode ()
	{
		isEnd = false ; 
		
		for (int i = 0 ; i < 26 ; i ++ ) 
			children [ i ] = NULL ; 
		
	}
};



class Dictionary 
{
	TrieNode * root ;
	
	
	public : 
	
	Dictionary()
	{
		root = new TrieNode (); 
	}
	
	
	void insert ( string word , string meaning ) 
	{
		
		int n = word.length() ; 
		TrieNode * temp = root ; 
		for (int i = 0 ; i < n ; i ++ )
		{
			int index = word [ i ] - 'a' ; 
			if ( temp -> children [ index ] == NULL )
				temp -> children [ index ] = new TrieNode () ; 
			temp = temp -> children [ index ] ; 
				
		}
		
		temp -> isEnd = true ;
		temp -> meaning = meaning ; 
	}
	
	
	TrieNode * search ( string word )
	{
		
		int n = word.length() ; 
		TrieNode * temp = root ; 
		for (int i = 0 ; i < n ; i ++ )
		{
			int index = word [ i ] - 'a' ; 
			if ( temp -> children [ index ] == NULL )
				return NULL ; 
			temp = temp -> children [ index ] ; 
				
		}	
		if ( temp -> isEnd)
			return temp ; 
		return NULL  ; 
			
	}
	
	
	string FindMeaning ( string word  )
	{
		TrieNode * temp = search ( word ) ; 
		if ( !temp ) 
			return "Word Does not Exit" ; 
		else 
			return temp -> meaning ; 
	}
	
	bool IsEmpty( TrieNode * root )
	{
		for ( int i = 0 ; i < 26 ; i ++  ) 
			if ( root -> children [ i ] ) 
				return 0 ; 
				
			
		return 1 ; 
	}
	
	TrieNode * DeleteUtil ( TrieNode * root , string s, int n , int depth  )
	{
		if ( !root ) 
			return NULL ; 
		
		if ( depth == n ) 
		{
			if ( root -> isEnd ) 
				root -> isEnd = 0 ; 
			
			if ( IsEmpty( root )  ) 
			{
				delete (root ) ; 
				return NULL ; 
			}
			
			return root ; 
		}
		
		
		
		int index = s [ depth] - 'a' ; 
		
		root -> children [ index ] = DeleteUtil ( root -> children [ index ] , s , n , depth + 1 ) ; 
		
		
		
		if ( IsEmpty( root ) and root -> isEnd == 0 ) 
		{
			delete (root ) ; 
			return NULL ; 
		}
		
		
		return root ; 
	}	
	
	
	
	void  Delete ( string word ) 
	{
	 	 TrieNode * temp = search ( word ) ; 
		if ( !temp ) 
			return ; 
		else 
			DeleteUtil ( root , word ,word.length() , 0  ) ; 
	}
	
	
};
	
	
int main()
{
	int n ; 
	cin >> n ; 
	Dictionary d ; 
	
	
	for ( int i = 0 ; i < n ; i ++ )
	{
		string word , meaning ; 
		cin >> word >> meaning ; 
		d.insert ( word , meaning ) ; 
	}
	
	int q ; 
	cin >> q ; 
	while ( q -- )
	{
		int x ; 
		cin >> x ;
		string word ; cin >> word ; 
		if ( x ) 
		{
			cout << d.FindMeaning ( word ) << endl ; 
		}
		else 
		{
			d.Delete ( word ) ; 
		}
	}
}
