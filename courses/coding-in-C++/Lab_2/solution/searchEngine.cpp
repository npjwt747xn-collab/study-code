/**
 * @file search_engine.cpp
 * @brief Implementation of the SearchEngine class.
 */

#include "searchEngine.hpp"

#include <algorithm>
#include <iostream>

int SearchEngine::total_queries = 0;

SearchEngine::SearchEngine()
    : web_resources(), current_query(), current_search_results()
{
}

void SearchEngine::printInfo() const
{
    std::cout << "SearchEngine information\n";
    std::cout << "Indexed resources: " << web_resources.size() << '\n';
    std::cout << "Current query: \"" << current_query.getQuery() << "\"\n";
    std::cout << "Stored search results: "
              << current_search_results.size()
              << '\n';
}

int SearchEngine::getTotalQueries()
{
    return total_queries;
}

void SearchEngine::incTotalQueries()
{
    total_queries++;
}

void SearchEngine::addResource(const WebResource &resource)
{
    web_resources.push_back(resource);

    if (current_query.isValid())
    {
        updateCurrentSearchResults();
    }
}

void SearchEngine::removeResource(const std::string &url)
{
    std::vector<WebResource>::iterator new_end =
        std::remove_if(
            web_resources.begin(),
            web_resources.end(),
            [&url](const WebResource &resource)
            {
                return resource.getUrl() == url;
            });

    web_resources.erase(new_end, web_resources.end());

    if (current_query.isValid())
    {
        updateCurrentSearchResults();
    }
    else
    {
        current_search_results.clear();
    }
}

SearchQuery SearchEngine::getCurrentQuery() const
{
    return current_query;
}

void SearchEngine::setCurrentQuery(const SearchQuery &query)
{
    current_query = query;

    if (current_query.isValid())
    {
        incTotalQueries();
        updateCurrentSearchResults();
    }
    else
    {
        current_search_results.clear();
    }
}

std::vector<WebResource> SearchEngine::getSearchResults() const
{
    return current_search_results;
}

void SearchEngine::sortCurrentResources()
{
    std::sort(
        current_search_results.begin(),
        current_search_results.end(),
        [](const WebResource &left, const WebResource &right)
        {
            return left.getRanking() > right.getRanking();
        });
}

void SearchEngine::printRelevantResults() const
{
    if (current_search_results.empty())
    {
        std::cout << "No relevant results found.\n";
        return;
    }

    std::cout << "Relevant search results for query \""
              << current_query.getQuery()
              << "\"\n";

    for (std::size_t index = 0; index < current_search_results.size(); index++)
    {
        const WebResource &resource = current_search_results[index];

        std::cout << index + 1 << ". ";
        std::cout << resource.getUrl();
        std::cout << " | ranking: " << resource.getRanking();
        std::cout << " | popular: " << std::boolalpha << resource.isPopular();
        std::cout << '\n';
    }
}

bool SearchEngine::queryInResource(
    const SearchQuery &query,
    const WebResource &resource) const
{
    if (!query.isValid())
    {
        return false;
    }

    return resource.getContent().find(query.getQuery()) != std::string::npos;
}

void SearchEngine::updateCurrentSearchResults()
{
    current_search_results.clear();

    for (std::size_t index = 0; index < web_resources.size(); index++)
    {
        const WebResource &current_resource = web_resources[index];

        if (queryInResource(current_query, current_resource))
        {
            current_search_results.push_back(current_resource);
        }
    }

    sortCurrentResources();

    const int max_results = current_query.getMaxResults();

    if (static_cast<int>(current_search_results.size()) > max_results)
    {
        current_search_results.resize(
            static_cast<std::size_t>(max_results));
    }
}