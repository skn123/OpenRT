#include "SamplerStratified.h"
#include "random.h"

namespace rt {
	//void CSamplerStratified::generateSeries(std::vector<Vec2f>& samples) const
	//{
	//	size_t nSamples = static_cast<size_t>(sqrt(samples.size()));
	//	float delta = 1.0f / nSamples;

	//	int s = 0;
	//	for (size_t y = 0; y < nSamples; y++)
	//		for (size_t x = 0; x < nSamples; x++) {
	//			float fx = static_cast<float>(x) + (m_jitter ? random::U<float>() : 0.5f);
	//			float fy = static_cast<float>(y) + (m_jitter ? random::U<float>() : 0.5f);
	//			samples[s] = delta * Vec2f(fx, fy);
	//			s++;
	//		}
	//}

    Vec2f CSamplerStratified::getNextSample(size_t i) const
    {
        const float delta = 1.0f / m_nSamples;
		const size_t y = i / m_nSamples;
		const size_t x = i % m_nSamples;
		
		if ((x + y * m_nSamples) != i) printf("Achtung!\n");

		const float fx = static_cast<float>(x) + (m_jitter ? random::U<float>() : 0.5f);
		const float fy = static_cast<float>(y) + (m_jitter ? random::U<float>() : 0.5f);
		
		return delta * Vec2f(fx, fy);
    }
}