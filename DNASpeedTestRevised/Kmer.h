#pragma once
#include <string>

class kmer
{
private:
	static const int length = 13;
	char data[length+1];

public:
	kmer(const kmer& src)
	{
		strcpy_s(data, sizeof(data),src.data);
	}
	
	static kmer First()
	{
		kmer k;
		std::memset(k.data, options[opt_begin], length);
		return k;
	}

	static kmer Last()
	{
		kmer k;
		std::memset(k.data, options[opt_last], length);
		return k;
	}

	operator const char* () const
	{
		return data;
	}

	static friend bool operator ==(const kmer& lhs, const kmer& rhs)
	{
		return strcmp(lhs.data, rhs.data) == 0;
	}

	static friend auto operator !=(const kmer& lhs, const kmer& rhs) -> bool
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
			next.data[i] = convert(data[i]);
			if (next.data[i] != options[opt_begin])
				break;
		}
		return next;
	}

	kmer& operator++()
	{
		for (int i = 0; i < length; i++)
		{
			data[i] = convert(data[i]);
			if (data[i] != options[opt_begin])
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
		// The rest will be filled in a minute.
		data[length] = 0;
	}
	
};

