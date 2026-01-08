import sqlite3

conn = sqlite3.connect("music_ai.db")
cursor = conn.cursor()

cursor.execute("""
CREATE TABLE IF NOT EXISTS songs (
    id TEXT PRIMARY KEY,
    slug TEXT UNIQUE,
    title TEXT,
    mix_path TEXT,
    duration_sec REAL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
)
""")

cursor.execute("""
CREATE TABLE IF NOT EXISTS stems (
    id TEXT PRIMARY KEY,
    song_id TEXT,
    original_name TEXT,
    stem_key TEXT,
    stem_group TEXT,
    file_path TEXT,
    duration_sec REAL,
    channels INT,
    layer_index INT
)
""")

conn.commit()
cursor.close()
conn.close()