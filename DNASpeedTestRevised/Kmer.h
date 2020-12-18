#pragma once
#include <string>

class kmer
{
	static const int length = 13;
	char s[length+1];



public:
	kmer(const kmer& src)
	{
		strcpy_s(s, sizeof(s),src.s);
	}

	
	
	static kmer First()
	{
		kmer k;
		std::memset(k.s, options[opt_begin], length);
		return k;
	}

	static kmer Last()
	{
		kmer k;
		std::memset(k.s, options[opt_last], length);
		return k;
	}

	operator const char* () const
	{
		return s;
	}

	static friend bool operator ==(const kmer& lhs, const kmer& rhs)
	{
		return strcmp(lhs.s, rhs.s) == 0;
	}
	static friend bool operator !=(const kmer& lhs, const kmer& rhs)
	{
		return !(lhs == rhs);
	}

	static const char options[6]; // = "ACGTA";
	static const int opt_begin = 0;
	static const int opt_last = 3;


	/// <summary>
	/// Return the next pattern in the sequence after the given k-mer.
	/// (You must call increment on the value returned to get the pattern after that)
	/// </summary>
	/// <returns></returns>
	kmer Increment()
	{
		kmer next(*this);
		
		for (int i = 0; i < length; i++)
		{
			next.s[i] = convert(s[i]);
			if (next.s[i] != options[opt_begin])
				break;
		}
		return next;
	}

	kmer& operator++()
	{
		for (int i = 0; i < length; i++)
		{
			s[i] = convert(s[i]);
			if (s[i] != options[opt_begin])
				break;
		}
		return *this;
	}
	

private:
	static char convert(char c)
	{
		const char* ptr = strchr(options, c);
		return *(++ptr);
	}
	
	kmer()
	{
		s[length] = 0;
	}
	
};

