module;
export module igame;

export import turn;
export import <algorithm>;
export import <memory>;

namespace skribbl
{

	export class IGame
	{
	public:
		using IGamePtr = std::shared_ptr<class IGame>;

	public:
		static IGamePtr Factory();
		virtual ~IGame() = default;
		virtual std::vector<Player* > leaderboard() = 0;
		virtual void start() = 0;
		virtual void addPlayer(const std::string& name) = 0;
		virtual bool verifyGuess(const std::string& guess) = 0;
	};
}