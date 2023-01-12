#include "StructGame.hpp"

namespace ScoreGame{
Scores::Scores(int score, int lives)
{
    ScoreGame::Scores::m_lives = lives;
    ScoreGame::Scores::m_score = score;
}
};
