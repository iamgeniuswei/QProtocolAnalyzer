#ifndef NSTIME_H
#define NSTIME_H
#include "qpautilization_global.h"
#include <glib.h>
/** @file
 * Definition of data structure to hold time values with nanosecond resolution
 */

/** data structure to hold time values with nanosecond resolution*/
class nstime_t{
public:
    nstime_t() = default;
    nstime_t(const nstime_t &ns)
    {
        secs = ns.secs;
        nsecs = ns.nsecs;
    }
    bool nstime_is_zero() const;
    void nstime_set_unset();
    bool nstime_is_unset() const;
    nstime_t& nstime_delta(const nstime_t &b, const nstime_t &a);
    nstime_t& nstime_sum(const nstime_t &b, const nstime_t &a);
    int nstime_cmp(const nstime_t &a);

    time_t g_secs() const
    {
        return secs;
    }
    int g_nsecs() const
    {
        return nsecs;
    }
    void s_secs(const time_t value)
    {
        secs = value;
    }

    void s_nsecs(const int value)
    {
        nsecs = value;
    }


private:
    time_t secs = 0;
    int nsecs = 0;
};


/* functions */

/** duplicate the current time
 *
 * a = b
 */
QPAUTILIZATIONSHARED_EXPORT void nstime_copy(nstime_t *a, const nstime_t *b);

/** calculate the delta between two times (can be negative!)
 *
 * delta = b-a
 *
 * Note that it is acceptable for two or more of the arguments to point at the
 * same structure.
 */
QPAUTILIZATIONSHARED_EXPORT void nstime_delta(nstime_t *delta, const nstime_t *b, const nstime_t *a );

/** calculate the sum of two times
 *
 * sum = a+b
 *
 * Note that it is acceptable for two or more of the arguments to point at the
 * same structure.
 */
QPAUTILIZATIONSHARED_EXPORT void nstime_sum(nstime_t *sum, const nstime_t *b, const nstime_t *a );

/** sum += a */
#define nstime_add(sum, a) nstime_sum(sum, sum, a)

/** sum -= a */
#define nstime_subtract(sum, a) nstime_delta(sum, sum, a)

/** compare two times are return a value similar to memcmp() or strcmp().
 *
 * a > b : > 0
 * a = b : 0
 * a < b : < 0
 */
QPAUTILIZATIONSHARED_EXPORT int nstime_cmp (const nstime_t *a, const nstime_t *b );

/** converts nstime to double, time base is milli seconds */
QPAUTILIZATIONSHARED_EXPORT double nstime_to_msec(const nstime_t *nstime);

/** converts nstime to double, time base is seconds */
QPAUTILIZATIONSHARED_EXPORT double nstime_to_sec(const nstime_t *nstime);

/** converts Windows FILETIME to nstime, returns TRUE on success,
    FALSE on failure */
QPAUTILIZATIONSHARED_EXPORT gboolean filetime_to_nstime(nstime_t *nstime, guint64 filetime);

/** converts time like Windows FILETIME, but expressed in nanoseconds
    rather than tenths of microseconds, to nstime, returns TRUE on success,
    FALSE on failure */
QPAUTILIZATIONSHARED_EXPORT gboolean nsfiletime_to_nstime(nstime_t *nstime, guint64 nsfiletime);

#endif // NSTIME_H
