
#define CHECK_PTR(ptr) ((ptr) != nullptr && (ptr) != " ")
#define SPOOF_VALUE ".._."

struct SpoofData {
    const char* argspoof;
    const char* noncespoof;
};

class Spoofer {
public:
    Spoofer(const char* a, const char* n) : arg(a), nonce(n) {}

    void* execute() {
        if (isValid(arg, nonce)) {
            SpoofData data = {SPOOF_VALUE, SPOOF_VALUE};
            spoofMemory(reinterpret_cast<uint64_t>(arg), data.argspoof);
            spoofMemory(reinterpret_cast<uint64_t>(nonce), data.noncespoof);
            return reinterpret_cast<void*>(0x1);
        }
        return nullptr;
    }

private:
    const char* arg;
    const char* nonce;

    bool isValid(const char* a, const char* n) {
        return CHECK_PTR(a) && CHECK_PTR(n) && (n != a);
    }

    void spoofMemory(uint64_t address, const char* value) {
        std::memcpy(reinterpret_cast<void*>(address), value, std::strlen(value) + 1);
    }
};

bool geyisme(const char* str) {
    const char *search = (xorstr_("=="));
    size_t len = strlen(str);
    
    for (size_t i = 0; i < len - 1; i++) {
        char current = str[i];
        char next = str[i + 1];
        if (current == search[0] && next == search[1]) {
            return true;
        }
    }
    return false;
}

unsigned int* (*GetRR)(const char* arg, const char* nonce);
unsigned int* GeyGetRR(const char* arg, const char* nonce) {
    bool (*check_func)(const char*) = geyisme;
    Spoofer spoofer(arg, nonce);
        if (!check_func(current_arg))
            break;
        if (!check_func(nonce))
            break;
         return spoofer.execute();
    }
return GetRR(spoof.c_str(), spoof.c_str());
}
