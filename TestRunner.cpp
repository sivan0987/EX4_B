// #define DOCTEST_CONFIG_IMPLEMENT
// #include "doctest.h"
// using namespace doctest;

// const int MIN_TESTS = 20;

// int return_code = -1;

// struct ReporterCounter: public ConsoleReporter {
//     ReporterCounter(const ContextOptions& input_options)
//             : ConsoleReporter(input_options) {}

//     void test_run_end(const TestRunStats& run_stats) override {
//         if (run_stats.numAsserts >= MIN_TESTS) {
//             return_code = 0;
//         } else {
//             std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl;
//             return_code = 1;
//         }
//     }
// };

// REGISTER_REPORTER("counter", 1, ReporterCounter);

// int main(int argc, char** argv) {
//     Context context;
//     context.addFilter("reporters", "counter");
//     context.run();
//     return return_code;
// }
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;


struct ReporterGrader: public ConsoleReporter {
    ReporterGrader(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        ConsoleReporter::test_run_end(run_stats);
        int numAsserts = run_stats.numAsserts >=  MIN_TESTS? run_stats.numAsserts:  MIN_TESTS;
        float grade = (run_stats.numAsserts - run_stats.numAssertsFailed) * 100 / numAsserts;
        // std::cout << "Grade: " << grade << std::endl;
    }
};

REGISTER_REPORTER("grader", /*priority=*/1, ReporterGrader);

int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "grader");
    return context.run();
}