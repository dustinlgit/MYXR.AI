import sqlite3

con =  sqlite3.connect("myxr.db")
cur = con.cursor()

cur.execute( "PRAGMA foreign_keys = ON;" )

# create SONGS table
cur.execute("""
CREATE TABLE IF NOT EXISTS songs (
    id TEXT PRIMARY KEY,
    title TEXT NOT NULL,
    artist TEXT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP    
);
""")


# create AUDIO_FILES table
cur.execute("""
CREATE TABLE IF NOT EXISTS audio_files (
    id TEXT PRIMARY KEY,
    storage_backend TEXT NOT NULL,     -- local | s3
    storage_path TEXT NOT NULL,
    format TEXT,
    duration_sec REAL,
    channels INTEGER,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
""")


# create MIX_VERSIONS table
cur.execute("""
CREATE TABLE IF NOT EXISTS mix_versions (
    id TEXT PRIMARY KEY,
    song_id TEXT NOT NULL,
    audio_file_id TEXT NOT NULL,
    version_type TEXT NOT NULL,        -- unmastered | mastered
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (song_id) REFERENCES songs(id),
    FOREIGN KEY (audio_file_id) REFERENCES audio_files(id)
);
""")


# create STEMS table
cur.execute("""
CREATE TABLE IF NOT EXISTS stems (
    id TEXT PRIMARY KEY,
    song_id TEXT NOT NULL,
    audio_file_id TEXT NOT NULL,
    stem_key TEXT NOT NULL,             -- drums, vocals, bass
    stem_group TEXT,                    -- rhythm, music, fx
    layer_index INTEGER,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (song_id) REFERENCES songs(id),
    FOREIGN KEY (audio_file_id) REFERENCES audio_files(id)
);
""")


# create CATEGORIES table
cur.execute("""
CREATE TABLE IF NOT EXISTS categories (
    id TEXT PRIMARY KEY,
    name TEXT UNIQUE NOT NULL
);
""")

# create SONG_CATEGORIES table
    # many-to-many relationship
cur.execute("""
CREATE TABLE IF NOT EXISTS song_categories (
    song_id TEXT NOT NULL,
    category_id TEXT NOT NULL,
    PRIMARY KEY (song_id, category_id),
    FOREIGN KEY (song_id) REFERENCES songs(id),
    FOREIGN KEY (category_id) REFERENCES categories(id)
);
""")



con.commit()
con.close()