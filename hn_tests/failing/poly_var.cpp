#include <hn/lib.hpp>

ff::IO<void> hnMain()
{
	boost::function<ff::IO<void> (t0)> x = &ff::print<t0>;
	return x(2);
};
