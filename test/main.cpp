#include <complex>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <ppp/Matrix.hpp>
#include <span>
#include <string_view>
#include <vector>

std::size_t passes{0};
std::size_t fails{0};

bool TestHeadlessPrint() {
    std::vector<std::vector<float>> data{
        {3.0, 4.0},
        {3.0, 4.0},
    };

    std::optional<ppp::Matrix<float>> lvalue{ppp::Matrix<float>::New(data)};

    if (lvalue.has_value()) {
        std::cout << "Test: TestHeadlessPrint Passed!" << std::endl
                  << "Matrix Used: " << std::endl
                  << std::endl;
        std::cout << lvalue.value() << std::endl;
        passes++;
        return true;
    } else {
        std::cout << "Test: TestHeadlessPrint Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    }
}

bool TestEmptyPrint() {
    std::optional<ppp::Matrix<float>> empty{ppp::Matrix<float>::New()};

    if (empty.has_value()) {
        std::cout << "Test: TestEmptyPrint Passed!" << std::endl
                  << "Matrix Used: " << std::endl
                  << std::endl;
        std::cout << empty.value() << std::endl;
        passes++;
        return true;
    } else {
        std::cout << "Test: TestEmptyPrint Failed..." << std::endl << std::endl;
        fails++;
        return false;
    }
}

bool TestComplexPrint() {
    std::vector<std::vector<std::complex<float>>> complex{{
        {std::complex<float>(3.0, 3.0), std::complex<float>(4.0, 4.0)},
        {std::complex<float>(5.0, 5.0), std::complex<float>(6.0, 6.0)},
    }};

    std::optional<ppp::Matrix<std::complex<float>>> cmp{
        ppp::Matrix<std::complex<float>>::New(complex)};

    if (cmp.has_value()) {
        std::cout << "Test: TestComplexPrint Passed!" << std::endl
                  << "Matrix Used: " << std::endl
                  << std::endl;
        std::cout << cmp.value() << std::endl;
        passes++;
        return true;
    } else {
        std::cout << "Test: TestComplexPrint Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    }
}

bool TestInsertingHeaders() {
    std::vector<std::vector<float>> data{
        {3.0, 4.0},
        {3.0, 4.0},
    };

    std::optional<ppp::Matrix<float>> lvalue{ppp::Matrix<float>::New(data)};
    if (!lvalue.has_value()) {
        std::cout << "Test: TestInsertingHeaders Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    }

    std::vector<std::string_view> headers{"Foo", "Bar"};
    if (const std::optional<std::uint8_t> result{
            lvalue.value().SetHeaders(headers)};
        result.has_value()) {
        std::cout << "Test: TestInsertingHeaders Passed!" << std::endl
                  << "Matrix Used: " << std::endl
                  << std::endl;
        std::cout << lvalue.value() << std::endl;
        passes++;
        return true;
    } else {
        std::cout << "Test: TestInsertingHeaders Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    }
}

bool TestBadShapeCatching() {
    std::vector<std::vector<float>> data{
        {3.0, 4.0},
        {3.0},
    };

    std::optional<ppp::Matrix<float>> lvalue{ppp::Matrix<float>::New(data)};
    if (lvalue.has_value()) {
        std::cout << "Test: TestInsertingHeaders Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    } else {
        std::cout << "Test: TestBadShapeCatching Passed!" << std::endl
                  << std::endl;
        passes++;
        return true;
    }
}

bool TestAddition() {
    std::vector<std::vector<float>> data{
        {3.0, 4.0},
        {3.0, 4.0},
    };

    std::optional<ppp::Matrix<float>> lhs{ppp::Matrix<float>::New(data)};
    std::optional<ppp::Matrix<float>> rhs{ppp::Matrix<float>::New(data)};
    if (!lhs.has_value() || !rhs.has_value()) {
        std::cout << "Test: TestAddition Failed..." << std::endl << std::endl;
        fails++;
        return false;
    } else {
        auto sum = lhs.value() + rhs.value();
        if (sum.has_value()) {
            std::cout << "Test: TestAddition Passed!" << std::endl << std::endl;
            std::cout << sum.value() << std::endl;
            passes++;
            return true;
        } else {
            fails++;
            return false;
        }
    }
}

bool TestSubtraction() {
    std::vector<std::vector<float>> data{
        {3.0, 4.0},
        {3.0, 4.0},
    };

    std::optional<ppp::Matrix<float>> lhs{ppp::Matrix<float>::New(data)};
    std::optional<ppp::Matrix<float>> rhs{ppp::Matrix<float>::New(data)};
    if (!lhs.has_value() || !rhs.has_value()) {
        std::cout << "Test: TestSubtraction Failed..." << std::endl
                  << std::endl;
        fails++;
        return false;
    } else {
        auto sum = lhs.value() - rhs.value();
        if (sum.has_value()) {
            std::cout << "Test: TestSubtraction Passed!" << std::endl
                      << std::endl;
            std::cout << sum.value() << std::endl;
            passes++;
            return true;
        } else {
            fails++;
            return false;
        }
    }
}

int main(void) {
    bool test_result{TestHeadlessPrint() && TestEmptyPrint() &&
                     TestComplexPrint() && TestInsertingHeaders() &&
                     TestBadShapeCatching() && TestAddition() &&
                     TestSubtraction()};

    std::cout << std::endl
              << "--------------------------------- Test Summary "
                 "---------------------------------"
              << std::endl
              << std::endl
              << "Tests Passed: " << passes << std::endl
              << "Tests Failed: " << fails << std::endl
              << std::endl
              << "------------------------------------ Result "
                 "------------------------------------"
              << std::endl
              << std::endl;
    if (test_result) {
        std::cout << "                               " << "All tests passed!!"
                  << "                               " << std::endl;
    } else {
        std::cout << "                              " << "Some tests failed..."
                  << "                              " << std::endl;
    }
}
