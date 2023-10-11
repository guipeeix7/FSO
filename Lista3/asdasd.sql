- ---------------------   << Trabalho Final - Video Games (Tema 1)
VALUES ('',''),;  >>   ---------------------
--                                   SCRIPT DE POPULA (DML)
VALUES ('',''),;                                   
-- Data Criacao ...........: 09/12/2022
-- Autor(es)
VALUES ('',''),; ..............: Guilherme Peixoto Lima
-- Banco de Dados .........: MySQL
-- Banco de Dados(nome)
VALUES ('',''),; ...: TF1C_Guilherme
-- 
-- 
-- PROJETO => 01 Base de Dados
--         => 31 Tabelas
-- 
-- --------------------------------------------------------------------------------------------

USE TF1C_Guilherme;
   
    
    
INSERT INTO PESSOA (
    identificadorUnico,
    dataNacimento,
    email ,
    tipoSanguineo ,
    sexo ,
    estadoCivil ,
    profissao ,
    tipoIdentificacao ,
    tipoPEssoa ,
)
VALUES ('',''),;;

INSERT INTO CLIENTE (
    identificadorUnico 
)
VALUES ('',''),;;

INSERT INTO TERAPEUTA (
    tipoTerapeuta ,
    dataSaida ,
    dataAdmissao ,
    identificadorUnico ,
)
VALUES ('',''),;ENGINE = InnoDB;


INSERT INTO SECAO_PAGAMENTO (
    periodicidadeAcompanhamento ,
    numeroSecoes ,
    precoTotal,
    dataSecao ,
    tipoSecao ,
    identificadorUnico ,
    pagamentoId ,
    tipo ENUM ,
    criadoEm ,
    atualizadoEm,
    parcelas,
    status
)
VALUES ('',''),;;

INSERT INTO ORGAOCHOQUE (
    orgaoId ,
    nome 
)
VALUES ('',''),;
INSERT INTO RELATORIO_ACOMPANHAMENTO (
    relatorioId,
    orientNeutPolMagnetica ,
    dataRelatorio ,
    infoCliente ,
    tipoAcompanhamento ,
    idAcompanhamento ,
    idSecao ,
        
)
VALUES ('',''),;

INSERT INTO RECEITA (
    statusReceita,
    idRelatorio ,
    pessoaIdentificadorUnico ,
    terapeutaIdentificadorUnico,
    
)
VALUES ('',''),;


INSERT INTO CURSO (
    nome  ,
    idCurso 
)
VALUES ('',''),;

INSERT INTO telefone (
    telefoneId,
    telefone ,
    userId 
)
VALUES ('',''),;
 
INSERT INTO CONSULTORIO (
    idReceitaConsultorio ,
)
VALUES ('',''),;

INSERT INTO FARMACIA (
    idReceitaFarmacia
)
VALUES ('',''),;

INSERT INTO CONTAMINACAO (
    recomendacao ,
    contaminacaoId ,
    relatorioId 
)
VALUES ('',''),;

INSERT INTO METAL (
    metalId ,
    nome 
)
VALUES ('',''),;

INSERT INTO ITEMFARMACIA (
    nomeItem 

)
VALUES ('',''),;



INSERT INTO ITEM (
    nome ,
    precoVenda,
    descricao 
)
VALUES ('',''),;

INSERT INTO ESTOQUE (
    idItemEstoque ,
    quantidade ,
    dataAtualizacao,
    precoCusto ,
    itemNome ,
)
VALUES ('',''),;

INSERT INTO ENDERECO (
	idEndereco, 
    cep ,
    cidade,
    complemento ,
)
VALUES ('',''),;

INSERT INTO FARMACIA_PARCEIRA (
    nomeFarmacia 
)
VALUES ('',''),;

INSERT INTO telefoneFarmacia (
    telefoneFarmacia ,
    idFarmacia
)
VALUES ('',''),;

INSERT INTO habita (
	idEndereco,
    identificadorUnico ,
    
)
VALUES ('',''),;

INSERT INTO tem (
    relatorioId 
    orgaoChoqueNome,
    
)
VALUES ('',''),;

INSERT INTO contem (
    contaminacaoId ,
    metalNome ,
    
)
VALUES ('',''),;

INSERT INTO inclui (
    itemNome ,
    idReceitaConsultorio ,
)
VALUES ('',''),;


INSERT INTO dispoe (
    fk_ITEM_nome ,
    fk_idFarmacia,
    
)
VALUES ('',''),;

INSERT INTO cursa (
    fk_TERAPEUTA_FK_PESSOA_identificadorUnico ,
    fk_CURSO_idCurso ,
)
VALUES ('',''),;

INSERT INTO localizada (
    idSecao ,
    idEndereco,
)
VALUES ('',''),;


INSERT INTO situada (
	idEndereco,
    idFarmacia ,
    
)
VALUES ('',''),;

INSERT INTO entregue (
    idReceita ,
    idFarmacia,
)
VALUES ('',''),;


INSERT INTO gerencia (
    fk_TERAPEUTA_FK_PESSOA_identificadorUnico ,
    fk_ESTOQUE_idItemEstoque ,
    fk_ESTOQUE_FK_ITEM_nome ,
)
VALUES ('',''),;

INSERT INTO efetua (
    identificadorUnico,
    idSecao ,
)
VALUES ('',''),;
