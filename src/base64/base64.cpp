#include "base64.h"

#include <Tanja84dk/crypt/base64/base64.h>
#include <renenyffenegger/base64.h>

Tanja84dk::crypt::Base64::Base64(const std::string &input_data) noexcept { this->_input_data = input_data; }

std::string Tanja84dk::crypt::Base64::encode() const noexcept { return base64_encode(this->_input_data); }

std::string Tanja84dk::crypt::Base64::encode_url_safe(bool url_safe) const noexcept {
    if (url_safe == false) {
        return base64_encode(this->_input_data);
    }
    return base64_encode(this->_input_data, true);
}

std::string Tanja84dk::crypt::Base64::decode() const noexcept { return base64_decode(this->_input_data); }
