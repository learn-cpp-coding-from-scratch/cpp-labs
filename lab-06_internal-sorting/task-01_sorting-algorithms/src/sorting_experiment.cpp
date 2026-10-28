#include "sorting_experiment.hpp"

// TODO: напишите решение

std::vector<SortingAlgorithm> sortingAlgorithms()
{
    // TODO: напишите решение
    return {};
}

Measurement measureSort(SortFunction sort, std::vector<int>& numbers)
{
    Measurement measurement;
    // TODO: напишите решение
    return measurement;
}

Measurement averageMeasurement(const std::vector<Measurement>& measurements)
{
    Measurement average;
    // TODO: напишите решение
    return average;
}

ResultsBlock averageBlock(const std::string& title, const std::vector<ResultsBlock>& blocks)
{
    ResultsBlock result{.title = title, .measurements = {}};
    // TODO: напишите решение
    return result;
}

void writeResultsTable(std::ostream& out, const std::vector<std::size_t>& sizes,
                       const std::vector<SortingAlgorithm>& algorithms, const std::vector<ResultsBlock>& blocks)
{
    // TODO: напишите решение
}
