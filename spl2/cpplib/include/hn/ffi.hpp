namespace ff
{
	int incr(int);
	int sum(int, int);

	template <typename T> struct elist
	{
		static T value;
	};

	template <typename T> std::list<T> elist<T>::value = std::list<T>();

	template <typename T>
	struct thunk
	{
		typedef boost::function<T ()> type;
	};

	template <typename T> struct IO
	{
		typename thunk<T>::type value;
		IO(typename thunk<T>::type _v) : value (_v)
		{
		};

		IO()
		{

		}
	};

	template <typename T1, typename T2> 
	struct bind_impl
	{
		IO<T1> a1;
		boost::function<IO<T2> (T1)> a2;
		T2 operator()()
		{
			return a2(a1.value()).value();
		}
	};

	/*

	x = readnum >>= (print >>= ret -1);

	readnum :: void -> int
	readnum = \void -> readnum_impl
	
	print :: int -> (\void -> void)
	print = \x -> (\void -> print_impl x)
	
	ret :: void -> int
	ret x = \void -> x

	bind :: (void -> t1) -> (t2 -> (\void -> 
	bind a b = \void -> 

	*/


	template <typename T1, typename T2> 
	IO<T2> bind(IO<T1> a1, boost::function<IO<T2> (T1)> a2)
	{
		bind_impl<T1, T2> impl = { a1, a2 };
		return impl;
	};


	template <typename T>
	void print_impl(T t)
	{
		std::cout << t << std::endl;		
	}


	template <typename T>
	IO<void> print(T t)
	{
		return boost::bind(&print_impl<T>, t);
	}

	inline
	boost::function<IO<void> (int)> fn2(IO<void> (*x)(int))
	{
		return x;
	}

	extern IO<int> readnum;

	template <typename T> 
	T read()
	{
		T t;
		std::cin >> t;
		return t;
	}
};

ff::IO<void> hnMain();