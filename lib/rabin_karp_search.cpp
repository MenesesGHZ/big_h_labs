#include "rabin_karp_search.hpp"
/* pat -> pattern
	txt -> text
	q -> A prime number
*/
rabin_karp::my_tuple rabin_karp::search(const char* pat, const char* filename, int q)
{
  // read file
	std::string txt = utils::read_file(filename);
  rabin_karp::my_tuple vec;

  // run algorithm
  int row = 1, column = 0;
	int M = strlen(pat);
	int N = txt.size();
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	for (i = 0; i < M; i++)	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}
	for (i = 0; i <= N - M; i++)
	{
    column++;
    if(txt[i] == '\n'){
      row++; 
      column = 0;
    }
		if ( p == t )
		{
			bool flag = true;
			for (j = 0; j < M; j++)
			{
				if (txt[i+j] != pat[j]){
				flag = false;
				break;
				}
			}		
			if (j == M)
        vec.push_back(std::make_tuple(row, column));
		}
		if ( i < N-M )
		{
			t = (d*(t - txt[i]*h) + txt[i+M])%q;
			if (t < 0)
			t = (t + q);
		}
	}
  return vec;
}