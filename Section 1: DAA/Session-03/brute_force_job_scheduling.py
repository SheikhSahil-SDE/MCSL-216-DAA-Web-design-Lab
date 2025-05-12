# Brute Force Job Scheduling

from itertools import permutations

def calculate_total_time(schedule):
    total_time = 0
    cumulative_time = 0
    for job_time in schedule:
        cumulative_time += job_time
        total_time += cumulative_time
    return total_time

def brute_force_job_scheduling(jobs):
    all_schedules = list(permutations(jobs))
    optimal_schedule = None
    optimal_time = float('inf')

    for schedule in all_schedules:
        total_time = calculate_total_time(schedule)
        if total_time < optimal_time:
            optimal_time = total_time
            optimal_schedule = schedule

    return all_schedules, optimal_schedule, optimal_time

# Example usage
jobs = [5, 8, 12]  # Service times for J1, J2, J3
all_schedules, optimal_schedule, optimal_time = brute_force_job_scheduling(jobs)

print("All possible schedules:")
for schedule in all_schedules:
    print(schedule)

print(f"\nOptimal schedule: {optimal_schedule}")
print(f"Total time for optimal schedule: {optimal_time}")

# Total number of schedules for N jobs
N = len(jobs)
total_schedules = len(all_schedules)
print(f"\nTotal number of job schedules for {N} jobs: {total_schedules}")
