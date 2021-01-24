//	 QMATH by nbq

#pragma once

#define X_PI 3.14159f
#define X_DIV 57.29577f

namespace qmath
{
	/* IMPLEMENTED IN x64 ASSEMBLY */

	extern "C" float _abs(float x);					// returns absolute value of x

	extern "C" float _min(float x, float y);		// returns minimum value of x or y

	extern "C" float _max(float x, float y);		// returns maximum value of x or y

	extern "C" float _floor(float x);				// returns x rounded to the nearest value

	extern "C" float _pow(float x, int y);			// returns x to the power of y (only positive)

	extern "C" float _sqrt(float x);				// returns square root of x


	/* IMPLEMENTED IN C++ */

	float _asin(float x)							// returns arc sin of x in radians
	{
		float negate = float(x < 0);
		x = _abs(x);
		float ret = -0.0187293;
		ret *= x;
		ret += 0.0742610;
		ret *= x;
		ret -= 0.2121144;
		ret *= x;
		ret += 1.5707288;
		ret = 3.14159265358979 * 0.5 - _sqrt(1.0 - x) * ret;
		return ret - 2 * negate * ret;
	}

	float _acos(float x)							// returns arc cos of x in radians
	{
		float negate = (x < 0);
		x = _abs(x);
		float ret = -0.01872f;
		ret = ret * x;
		ret = ret + 0.07426f;
		ret = ret * x;
		ret = ret - 0.21211f;
		ret = ret * x;
		ret = ret + 1.57072f;
		ret = ret * _sqrt(1.0f - x);
		ret = ret - 2 * negate * ret;
		return negate * X_PI + ret;
	}

	float _atan2(float x, float y)					// returns arc tan2 of x to the y in radians
	{
		float t0, t1, t3, t4;
		t3 = _abs(x);
		t1 = _abs(y);
		t0 = _max(t3, t1);
		t1 = _min(t3, t1);
		t3 = 1 / t0;
		t3 = t1 * t3;
		t4 = t3 * t3;
		t0 = -0.0134804f;
		t0 = t0 * t4 + 0.05747f;
		t0 = t0 * t4 - 0.12123f;
		t0 = t0 * t4 + 0.19563f;
		t0 = t0 * t4 - 0.33299f;
		t0 = t0 * t4 + 0.99999f;
		t3 = t0 * t3;
		t3 = (_abs(y) > _abs(x)) ? 1.57079f - t3 : t3;
		t3 = (x < 0) ? X_PI - t3 : t3;
		t3 = (y < 0) ? -t3 : t3;
		return t3;
	}

	float _atan(float x)							// returns arc tan of x in radians
	{
		return _atan2(x, 1);
	}
}