#pragma once

namespace bzc
{
	template <typename T> T pow(T base, T power)
	{
		T temp = base;

		for (unsigned int i = 0; i < power; i++)
		{
			base *= temp;
		}

		return base;
	}
}