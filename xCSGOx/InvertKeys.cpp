#include "InvertKeys.h"
#include <string>
_InvertKeys IK;
using namespace std;
const char* key_s;

const char* _InvertKeys::Invert(int key) {
	switch (key) {
	case 1:   key_s = "LPM"; break;
	case 2:   key_s = "PPM"; break;
	case 3:   key_s = "VK_CANCEL"; break;
	case 4:   key_s = "MMB"; break;
	case 5:   key_s = "M4"; break;
	case 6:   key_s = "M5"; break;
	case 7:   key_s = "---"; break;
	case 8:   key_s = "BACKSPACE"; break;
	case 9:   key_s = "TAB"; break;
	case 12:  key_s = "CLEAR"; break;
	case 13:  key_s = "MMB"; break;
	case 16:  key_s = "SHIFT"; break;
	case 17:  key_s = "CTRL"; break;
	case 18:  key_s = "ALT"; break;
	case 19:  key_s = "PAUSE"; break;
	case 20:  key_s = "CAPS LOCK"; break;
	case 27:  key_s = "ESC"; break;
	case 32:  key_s = "SPACE"; break;
	case 33:  key_s = "PAGE UP"; break;
	case 34:  key_s = "PAGE DOWN"; break;
	case 35:  key_s = "END"; break;
	case 36:  key_s = "HOME"; break;
	case 37:  key_s = "LEFT"; break;
	case 38:  key_s = "UP"; break;
	case 39:  key_s = "RIGHT"; break;
	case 40:  key_s = "DOWN"; break;
	case 41:  key_s = "SELECT"; break;
	case 42:  key_s = "PRINT"; break;
	case 43:  key_s = "EXECUTE"; break;
	case 44:  key_s = "PRT SCR"; break;
	case 45:  key_s = "INS"; break;
	case 46:  key_s = "DEL"; break;
	case 47:  key_s = "HELP"; break;
	case 48:  key_s = "0"; break;
	case 49:  key_s = "1"; break;
	case 50:  key_s = "2"; break;
	case 51:  key_s = "3"; break;
	case 52:  key_s = "4"; break;
	case 53:  key_s = "5"; break;
	case 54:  key_s = "6"; break;
	case 55:  key_s = "7"; break;
	case 56:  key_s = "8"; break;
	case 57:  key_s = "9"; break;
	case 65:  key_s = "A"; break;
	case 66:  key_s = "B"; break;
	case 67:  key_s = "C"; break;
	case 68:  key_s = "D"; break;
	case 69:  key_s = "E"; break;
	case 70:  key_s = "F"; break;
	case 71:  key_s = "G"; break;
	case 72:  key_s = "H"; break;
	case 73:  key_s = "I"; break;
	case 74:  key_s = "J"; break;
	case 75:  key_s = "K"; break;
	case 76:  key_s = "L"; break;
	case 77:  key_s = "M"; break;
	case 78:  key_s = "N"; break;
	case 79:  key_s = "O"; break;
	case 80:  key_s = "P"; break;
	case 81:  key_s = "Q"; break;
	case 82:  key_s = "R"; break;
	case 83:  key_s = "S"; break;
	case 84:  key_s = "T"; break;
	case 85:  key_s = "U"; break;
	case 86:  key_s = "V"; break;
	case 87:  key_s = "W"; break;
	case 88:  key_s = "X"; break;
	case 89:  key_s = "Y"; break;
	case 90:  key_s = "Z"; break;
	case 91:  key_s = "L-WIN"; break;
	case 92:  key_s = "R-WIN"; break;
	case 95:  key_s = "SLP"; break;
	case 96:  key_s = "NUM0"; break;
	case 97:  key_s = "NUM1"; break;
	case 98:  key_s = "NUM2"; break;
	case 99:  key_s = "NUM3"; break;
	case 100: key_s = "NUM4"; break;
	case 101: key_s = "NUM5"; break;
	case 102: key_s = "NUM6"; break;
	case 103: key_s = "NUM7"; break;
	case 104: key_s = "NUM8"; break;
	case 105: key_s = "NUM9"; break;
	case 106: key_s = "*"; break;
	case 107: key_s = "+"; break;
	case 108: key_s = "|"; break;
	case 109: key_s = "-"; break;
	case 110: key_s = ","; break;
	case 111: key_s = "/"; break;
	case 112: key_s = "F1"; break;
	case 113: key_s = "F2"; break;
	case 114: key_s = "F3"; break;
	case 115: key_s = "F4"; break;
	case 116: key_s = "F5"; break;
	case 117: key_s = "F6"; break;
	case 118: key_s = "F7"; break;
	case 119: key_s = "F8"; break;
	case 120: key_s = "F9"; break;
	case 121: key_s = "F10"; break;
	case 122: key_s = "F11"; break;
	case 123: key_s = "F12"; break;
	case 124: key_s = "F13"; break;
	case 125: key_s = "F14"; break;
	case 126: key_s = "F15"; break;
	case 127: key_s = "F16"; break;
	case 128: key_s = "F17"; break;
	case 129: key_s = "F18"; break;
	case 130: key_s = "F19"; break;
	case 131: key_s = "F20"; break;
	case 132: key_s = "F21"; break;
	case 133: key_s = "F22"; break;
	case 134: key_s = "F23"; break;
	case 135: key_s = "F24"; break;
	case 144: key_s = "NUMLCK"; break;
	case 145: key_s = "SCRLCK"; break;
	case 160: key_s = "LSHIFT"; break;
	case 161: key_s = "RSHIFT"; break;
	case 162: key_s = "LCTRL"; break;
	case 163: key_s = "RCTRL"; break;
	case 164: key_s = "LALT"; break;
	case 165: key_s = "RALT"; break;
	default: key_s = "None";
	}
	return key_s;
};
