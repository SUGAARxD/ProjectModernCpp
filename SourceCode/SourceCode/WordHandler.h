#include <vector>
#include <string>
#include <memory>
#include "Database.h"
#include <ranges>
import uniquerandom;

namespace skribbl
{
	class WordHandler
	{
	public:
		using WordHandlerPtr = std::unique_ptr<WordHandler>;

	public:
		WordHandler(skribbl::Database& db);
		~WordHandler() = default; 
		WordHandler(const WordHandler& wg)=delete; 
		WordHandler& operator=(const WordHandler&) = delete;
		WordHandler(WordHandler&& wg)noexcept = default;
		WordHandler& operator=(WordHandler&&)noexcept = default;

		void Reset();
		void ResetToInitialState();
		
		void AddCustomWord(const std::string& word);
		void AddCustomWordsToDatabase(uint8_t playersNumber);
		void UpdateCustomWordScore(int16_t score);
		
		bool AreCustomWordsLeft() const;
		const std::string& GetWord();
		const std::vector<uint8_t>& GenerateHint();

		uint8_t GetNumberCustomWord() const;


	private:
		std::string m_currentWord;
		UniqueRandom<int>::UniqueRandomPtr m_ur;
		skribbl::Database& m_db;
		std::vector<std::pair<std::string, int16_t>> m_customWords;
		std::vector<uint8_t> m_hint;
		int m_customWordPos;
	};
}