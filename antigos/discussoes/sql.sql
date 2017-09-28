CREATE  TABLE IF NOT EXISTS discussao (
  id SERIAL,
  prova_titulo VARCHAR(100) NULL ,
  prova_pdf_url VARCHAR(150) NULL ,
  prova_num_questoes INT NULL ,
  prova_num_questoes_ok INT NULL ,
  PRIMARY KEY (id) )
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table problema
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS problema (
  id SERIAL,
  letra CHAR NULL ,
  ok TINYINT(1) NULL ,
  titulo VARCHAR(45) NULL ,
  discussao_id INT NOT NULL ,
  conteudo text NULL ,
  PRIMARY KEY (id) );


-- -----------------------------------------------------
-- Table usuario
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS usuario (
  id SERIAL,
  nome VARCHAR(255) NOT NULL ,
  auth_key VARCHAR(32) NULL ,
  password_hash VARCHAR(255) NOT NULL ,
  email VARCHAR(255) NOT NULL ,
  status INT NOT NULL DEFAULT 10 ,
  hash_facebook VARCHAR(255) NULL ,
  PRIMARY KEY (id) );


-- -----------------------------------------------------
-- Table comentario
-- -----------------------------------------------------
CREATE  TABLE IF NOT EXISTS comentario (
  id SERIAL,
  fb_usuario VARCHAR(70) NULL ,
  conteudo text NULL ,
  problema_id INT NOT NULL ,
  usuario_id INT NOT NULL ,
  PRIMARY KEY (id) );