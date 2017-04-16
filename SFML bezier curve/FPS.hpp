#pragma once
#include <SFML\System.hpp>

namespace bzc
{
	class FPS
	{
	public:
		FPS() : _Frame(0), _Fps(0) {};

		void update(); // use on the end of game frame

		const unsigned int getFPS() const{ return _Fps; }

	private:
		unsigned int _Frame;
		unsigned int _Fps;
		sf::Clock _clock;
	};

	void FPS::update() 
	{
		if (_clock.getElapsedTime().asSeconds() >= 1.f)
		{
			_Fps = _Frame;
			_Frame = 0;
			_clock.restart();
		}

		++_Frame;
	}
} // dlaczego ró¿nice miedzy implementacj¹ w pliku cpp a hpp - przypomnieæ sobie