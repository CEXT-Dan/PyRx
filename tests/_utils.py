import secrets


def get_unique_command_name() -> str:
    """Generate a unique command name for testing."""
    return f"test_command_{secrets.token_hex(4)}"
