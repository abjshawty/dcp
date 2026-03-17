import threading


def schedule(f, n: int) -> None:
    # schedule calls f after n milliseconds using a background timer thread.
    timer = threading.Timer(n / 1000.0, f)
    timer.start()


def main():
    print("Problem 10:")
    done = threading.Event()
    schedule(done.set, 50)
    done.wait(timeout=2)
    assert done.is_set(), "assertion failed"
    print("All Tests Passed")
