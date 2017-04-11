#ifndef STANDARDCURSOR_HPP
#define STANDARDCURSOR_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#ifdef SFML_SYSTEM_WINDOWS
	#include <windows.h>
#elif defined(SFML_SYSTEM_LINUX)
	#include <X11/cursorfont.h>
	#include <X11/Xlib.h>
#else
	#error This OS is not yet supported by the cursor library.
#endif // SFML_SYSTEM_WINDOWS

namespace sf
{
	class StandardCursor
	{
	private:
#ifdef SFML_SYSTEM_WINDOWS

		HCURSOR Cursor;

#else

		XID Cursor;
		Display* display;

#endif // SFML_SYSTEM_WINDOWS

	public:
		enum TYPE {WAIT, TEXT, NORMAL, HAND};
		StandardCursor(const TYPE t);
		void set(const sf::WindowHandle& aWindowHandle) const;
		~StandardCursor();
	};
}

#endif // !STANDARDCURSOR_HPP
